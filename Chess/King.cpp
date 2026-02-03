#include "King.hpp"
#include "DomainException.hpp"

using namespace Entity;
using namespace Shield;
using namespace Utils;

/*// King class -- Implementation //*/

King::King(PieceGroup group, bool is_moved) : Piece(PieceType::King, group, is_moved) {}

King::King(PieceGroup group, const Position& position, bool is_moved) : Piece(PieceType::King, group, position, is_moved) {}

bool King::is_valid_move(const Position& target)
{
	bool validity = Piece::is_valid_move(target);
	auto diff_pos = Position::abs_difference(position.current, target);
	int row = diff_pos.get_row(), column = diff_pos.get_column();

	/*
	Valid Moves;
		A. (1, 0)
		B. (1, 1)
		C. (0, 1)
	*/
	if (row == column)
	{
		if (row != 1)	// B
			validity = false;
	}
	else
	{
		if (column == 0 && row != 1)	// A
			validity = false;
		else if (row == 0 && column != 1)	// C
			validity = false;
		else
			validity = false;
	}

	return validity;
}

void King::move(const Position& target)
{
	if (!is_valid_move(target))
		throw DomainException("The move is invalid.");

	Piece::move(target);
}
