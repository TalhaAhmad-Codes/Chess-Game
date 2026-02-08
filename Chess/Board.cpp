#include <iostream>
#include "PathMoveValidator.hpp"
#include "DomainException.hpp"
#include "PieceSymbols.hpp"
#include "Board.hpp"

using namespace std;
using namespace Utils;
using namespace Logic;
using namespace Entity;
using namespace Shield;
using namespace Interface;

/*// Board class -- Implementation //*/

// Constructor
Board::Board()
{
	//reset();
	clear();
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
	return (cell == nullptr) ? PieceGroup::NONE : cell->get_piece()->get_group();
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

ValidationResult Board::move_piece(Position& from, Position& to)
{
	auto source = get_cell(from), destination = get_cell(to);
	
	// If there's no piece
	if (source->is_empty())
		return ValidationResult::EMPTY_CELL;
	
	auto piece = source->get_piece();
	
	// Check for path
	ValidationResult result = PathMoveValidator::is_path_clear(from, to, *this, piece->get_type());

	if (result == ValidationResult::UNCLEAR_PATH)
	{
		if (get_cell(to)->get_piece()->get_group() == piece->get_group())
			return result;
	}
	else
	{
		get_cell(to)->make_empty();
	}

	try
	{
		result = piece->move(to);
		
		if (result == ValidationResult::OK)
		{
			source->make_empty();
			destination->place_piece(piece);
		}
		else
			return result;
	}
	catch (const DomainException& ex)
	{
		throw DomainException(ex.what());
	}

	return ValidationResult::OK;
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

// Debugging
void Board::display()
{
	char labels[2][8] = {{'1', '2', '3', '4', '5', '6', '7', '8'},
						{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};

	// Column labels
	cout << "  ";
	for (int i = 0; i < 8; i++)
	{
		cout << labels[1][i] << ' ';
	}
	cout << endl;

	// Grid & Row labels
	for (int i = 7; i >= 0; i--)
	{
		cout << labels[0][i] << ' ';	// Labels

		// Grid
		for (int j = 0; j < 8; j++)
		{
			auto cell = get_cell(Position(i, j));
			auto piece = cell->get_piece();

			(cell->is_empty()) ?
				cout << '.' :
				cout << PieceSymbol::get_symbol(piece->get_type(), piece->get_group());
			cout << ' ';
		}
		cout << endl;
	}
}
