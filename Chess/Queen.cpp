#include "Queen.hpp"
#include "DomainException.hpp"

using namespace Entity;
using namespace Utils;
using namespace Shield;

/*// Queen class -- Implementation //*/

Queen::Queen(PieceGroup group, bool is_moved) : Piece(PieceType::QUEEN, group, is_moved) {}

Queen::Queen(PieceGroup group, const Position& position, bool is_moved) : Piece(PieceType::QUEEN, group, position, is_moved) {}

bool Queen::is_valid_move(const Position& target)
{
	bool validity = Piece::is_valid_move(target);
	auto diff_pos = Position::abs_difference(position.current, target);
	int row = diff_pos.get_row(), column = diff_pos.get_column();

	/*
	Valid moves are:
		A. (0, n)		// Horizontal
		B. (n, 0)		// Vertical
		C. (n, n)		// Diagonal
	where 8 > n > 0.
	*/
	if (row != column)	// C
	{
		validity = false;
	}
	else
	{
		if (row != 0 && column != 0)	// A & B
			validity = false;
	}

	return validity;
}

void Queen::move(const Position& target)
{
	if (!is_valid_move(target))
		throw DomainException("The move is invalid.");

	Piece::move(target);
}
