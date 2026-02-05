#include "King.hpp"
#include "DomainException.hpp"

using namespace Entity;
using namespace Shield;
using namespace Utils;

/*// King class -- Implementation //*/

King::King(PieceGroup group, bool is_moved, bool is_alive) : Piece(PieceType::KING, group, is_moved, is_alive) {}

King::King(PieceGroup group, const Position& position, bool is_moved, bool is_alive) : Piece(PieceType::KING, group, position, is_moved, is_alive) {}

bool King::is_valid_move(const Position& target) const
{
	if (!Piece::is_valid_move(target))
		return false;

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
			return false;
	}
	else
	{
		if (column == 0 && row != 1)	// A
			return false;
		else if (row == 0 && column != 1)	// C
			return false;
	}

	return true;
}

void King::move(const Position& target)
{
	if (!is_valid_move(target))
		throw DomainException("The move is invalid.");

	Piece::move(target);
}
