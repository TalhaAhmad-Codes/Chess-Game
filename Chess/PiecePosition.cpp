#include "PiecePosition.hpp"
#include "DomainException.hpp"

using namespace Interface;
using namespace Shield;
using namespace Utils;
using namespace std;

/*// Piece Position structure -- Functions' Implementation //*/

// Constructor
PiecePosition::PiecePosition(Position* position)
{
	current = position;
}

// Getters
Position PiecePosition::get_current() const
{
	return *current;
}

Position PiecePosition::get_previous()
{
	if (!previous_moves.empty())
	{
		auto position = previous_moves.top();
		previous_moves.pop();
		return position;
	}

	return *current;
}

// Method - Movement
void PiecePosition::move(const Position& target, bool save_to_stack)
{
	// Move the piece and store position to the undo stack
	if (current != nullptr && save_to_stack)
		previous_moves.push(*current);
	
	current = new Position(target);
}

// Method - Get initial positions for piece
vector<Position> PiecePosition::initial_positions(PieceType type, PieceGroup group)
{
	vector<Position> positions;
	int row = (group == PieceGroup::WHITE) ? 0 : 7,	// Row
		column, columns[2];	// Column(s); Use single variable for only King and Queen
	if (type == PieceType::PAWN)	// Pawn case
		row += (group == PieceGroup::WHITE) ? 1 : -1;
	
	switch (type)
	{
		case PieceType::PAWN:
			for (int c = 0; c < 8; c++)
				positions.push_back(Position(row, c));
			break;

		case PieceType::BISHOP:
			columns[0] = 2;
			columns[1] = 5;
			for (auto&& column : columns)
				positions.push_back(Position(row, column));
			break;

		case PieceType::ROOK:
			columns[0] = 0;
			columns[1] = 7;
			for (auto&& column : columns)
				positions.push_back(Position(row, column));
			break;

		case PieceType::KNIGHT:
			columns[0] = 1;
			columns[1] = 6;
			for (auto&& column : columns)
				positions.push_back(Position(row, column));
			break;

		case PieceType::QUEEN:
			column = 3;
			positions.push_back(Position(row, column));
			break;

		case PieceType::KING:
			column = 4;
			positions.push_back(Position(row, column));
			break;

		default:
			throw DomainException("Invalid piece type.");
	}

	return positions;
}

// Destructor
PiecePosition::~PiecePosition()
{
	delete current;

	while (!previous_moves.empty())
		previous_moves.pop();
}
