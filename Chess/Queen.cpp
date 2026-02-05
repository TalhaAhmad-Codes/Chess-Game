#include "Queen.hpp"
#include "DomainException.hpp"

using namespace Entity;
using namespace Utils;
using namespace Shield;

/*// Queen class -- Implementation //*/

Queen::Queen(PieceGroup group, bool is_moved, bool is_alive) : Piece(PieceType::QUEEN, group, is_moved, is_alive) {}

Queen::Queen(PieceGroup group, const Position& position, bool is_moved, bool is_alive) : Piece(PieceType::QUEEN, group, position, is_moved, is_alive) {}

bool Queen::is_valid_move(const Position& target) const
{
	if (!Piece::is_valid_move(target)) return false;

	auto diff_pos = Position::abs_difference(position.current, target);
	int row = diff_pos.get_row(), column = diff_pos.get_column();

	/*
	Valid moves are:
		A. (0, n)		// Horizontal
		B. (n, 0)		// Vertical
		C. (n, n)		// Diagonal
	where 8 > n > 0.
	*/
	if (row == 0 && column != 0)
		return true;

	else if (row != 0 && column == 0)
		return true;

	else if (row == column)
		return true;

	return false;
}

void Queen::move(const Position& target)
{
	if (!is_valid_move(target))
		throw DomainException("The move is invalid.");

	Piece::move(target);
}
