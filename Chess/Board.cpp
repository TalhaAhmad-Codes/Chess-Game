#include "Board.hpp"
#include "DomainException.hpp"

using namespace std;
using namespace Utils;
using namespace Entity;
using namespace Shield;
using namespace Interface;

/*// Board class -- Implementation //*/

// Constructor
Board::Board()
{
	reset();
}

// Getters
Cell* Board::get_cell(const Position& position)
{
	position.against_negative_value();
	auto row = position.get_row(), column = position.get_column();
	return &grid[row][column];
}

bool Board::is_empty(const Position& position)
{
	return get_cell(position)->is_empty();
}

PieceGroup Board::get_piece_group(const Position& position)
{
	auto cell = get_cell(position);
	return (cell == nullptr) ? PieceGroup::NONE : cell->get_piece().get_group();
}

// Method - Place / Move piece around the grid
void Board::place_piece(Piece* piece, const Position& position)
{
	auto cell = get_cell(position);
	
	// Cell is not empty
	if (cell != nullptr)
		throw DomainException("Cell is not empty.");

	cell->place_piece(piece);
}

void Board::move_piece(const Position& from, const Position& to)
{
	auto source = get_cell(from), destination = get_cell(to);
	
	// If there's no piece
	if (source->is_empty())
		throw DomainException("No piece found at given position.");
	
	auto piece = source->get_piece();
	
	try
	{
		piece->move(to);
		source->make_empty();
		destination->place_piece(piece);
	}
	catch (const DomainException& ex)
	{
		throw DomainException(ex.what());
	}
}

// Method - Clear the board
void Board::clear()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			grid[i][j].make_empty();
		}
	}
}

// Method - Place all pieces at initial positions
void Board::reset_pieces()
{
	// Piece's group and type arrays
	PieceGroup groups[2] = { PieceGroup::WHITE, PieceGroup::BLACK };
	PieceType types[6] = { PieceType::PAWN, PieceType::BISHOP, PieceType::ROOK, PieceType::KNIGHT, PieceType::QUEEN, PieceType::KING };

	// Placing all pieces to their initial positions
	for (auto&& group : groups)
	{
		for (auto&& type : types)
		{
			auto positions = PiecePosition::initial_positions(type, group);

			for (auto&& position : positions)
			{
				auto cell = get_cell(position);
				auto piece = new Piece(type, group, position);
				cell->place_piece(piece);
			}
		}
	}
}

// Method - Reset the board
void Board::reset()
{
	clear();			// Clear the board
	reset_pieces();		// Reset pieces' positions
}
