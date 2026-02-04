#include "Pawn.hpp"
#include "DomainException.hpp"

using namespace Entity;
using namespace Utils;
using namespace Shield;

/*// Pawn class -- Implementation //*/

// Constructors
Pawn::Pawn(PieceGroup group, bool is_moved) : Piece(PieceType::PAWN, group, is_moved) {}

Pawn::Pawn(PieceGroup group, const Position& position, bool is_moved) : Piece(PieceType::PAWN, group, position, is_moved) {}

// Method - Move validity
bool Pawn::is_valid_move(const Position& target) const
{
	// Against reverse movement
	switch (group)
	{
		case PieceGroup::WHITE:
			if (target.get_row() < position.current.get_row())
				return false;
			break;
		
		case PieceGroup::BLACK:
			if (target.get_row() > position.current.get_row())
				return false;
			break;
	}

	if (!Piece::is_valid_move(target))
		return false;

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
			if (is_moved) return false;
		}
		else if (row != 1)	// A
			return false;
	}
	else if (column == 1)
	{
		if (row != 1)	// B
			return false;
	}
	else
		return false;

	return true;
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
	return position.current.get_row() == 7 && group == PieceGroup::WHITE ||
		   position.current.get_row() == 0 && group == PieceGroup::BLACK;
}
