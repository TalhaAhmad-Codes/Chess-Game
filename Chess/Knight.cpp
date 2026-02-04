#include "Knight.hpp"
#include "DomainException.hpp"

using namespace Utils;
using namespace Entity;
using namespace Shield;

/*// Knight class -- Implementation //*/

Knight::Knight(PieceGroup group, bool is_moved) : Piece(PieceType::KNIGHT, group, is_moved) {}

Knight::Knight(PieceGroup group, const Position& position, bool is_moved) : Piece(PieceType::KNIGHT, group, position, is_moved) {}

bool Knight::is_valid_move(const Position& target) const
{
	if (!Piece::is_valid_move(target)) return false;

	auto diff_pos = Position::abs_difference(position.current, target);
	int row = diff_pos.get_row(), column = diff_pos.get_column();

	/*
	Valid moves are
		A. (2, 1)
		B. (1, 2)
	*/
	if (row == 2)	// A
	{
		if (column != 1)
			return false;
	}
	else if (column == 2)	// B
	{
		if (row != 1)
			return false;
	}

	return true;
}

void Knight::move(const Position& target)
{
	if (!is_valid_move(target))
		throw DomainException("This move is invalid.");

	Piece::move(target);
}
