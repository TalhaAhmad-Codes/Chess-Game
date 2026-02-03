#include "Bishop.hpp"
#include "DomainException.hpp"

using namespace Utils;
using namespace Entity;
using namespace Shield;

/*// Bishop class -- Implementation //*/

Bishop::Bishop(PieceGroup group, bool is_moved) : Piece(PieceType::Bishop, group, is_moved) {}

Bishop::Bishop(PieceGroup group, const Position& position, bool is_moved) : Piece(PieceType::Bishop, group, position, is_moved) {}


bool Bishop::is_valid_move(const Position& target)
{
	bool validity = Piece::is_valid_move(target);
	auto diff_pos = Position::abs_difference(position.current, target);
	int row = diff_pos.get_row(), column = diff_pos.get_column();

	// Valid moves are (n, n), where 8 > n > 0
	if (row != column)
		validity = false;

	return validity;
}

void Bishop::move(const Position& target)
{
	if (!is_valid_move(target))
		throw DomainException("The move is invalid.");

	Piece::move(target);
}
