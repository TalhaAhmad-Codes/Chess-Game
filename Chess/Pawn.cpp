#include "Pawn.hpp"
#include "DomainException.hpp"

using namespace Entity;
using namespace Utils;
using namespace Shield;

/*// Pawn class -- Implementation //*/

// Constructors
Pawn::Pawn(PieceGroup group, bool is_moved) : Piece(PieceType::Pawn, group, is_moved) {}

Pawn::Pawn(PieceGroup group, const Position& position, bool is_moved) : Piece(PieceType::Pawn, group, position, is_moved) {}

// Method - Move validity
bool Pawn::is_valid_move(const Position& target)
{
	bool validity = Piece::is_valid_move(target);

	/*
	Valid moves are:
		A. (1, 0)	// Normal move
		B. (1, 1)	// Diagonal capture / en-passant
		C. (2, 0)	// Only first
	*/
	auto diff_pos = Position::abs_difference(position.current, target);
	int row = diff_pos.get_row(), column = diff_pos.get_column();

	if (column == 0)
	{
		// Double box
		if (row == 2)	// C
		{
			// If pawn is already moved
			if (is_moved)
			{
				double_box_move = false;
				validity = false;
			}

			double_box_move = true;
		}
		else if (row != 1)	// A
			validity = false;
	}
	else if (column == 1)
	{
		if (row != 1)	// B
			validity = false;
	}
	else if (column > 1 || row > 1)
		validity = false;

	return validity;
}

// Method - Move the piece
void Pawn::move(const Position& target)
{
	// In-valid move
	if (!is_valid_move(target))
		throw DomainException("The move is invalid.");

	// Move the piece
	Piece::move(target);
}

// Method - Pawn promotion check
bool Pawn::can_be_promoted() const
{
	return position.current.get_row() == 7 && group == PieceGroup::White ||
		   position.current.get_row() == 0 && group == PieceGroup::Black;
}
