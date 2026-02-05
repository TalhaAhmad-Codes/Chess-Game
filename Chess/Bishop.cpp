#include "Bishop.hpp"
#include "DomainException.hpp"

using namespace Utils;
using namespace Entity;
using namespace Shield;

/*// Bishop class -- Implementation //*/

Bishop::Bishop(PieceGroup group, bool is_moved, bool is_alive) : Piece(PieceType::BISHOP, group, is_moved, is_alive) {}

Bishop::Bishop(PieceGroup group, const Position& position, bool is_moved, bool is_alive) : Piece(PieceType::BISHOP, group, position, is_moved, is_alive) {}


bool Bishop::is_valid_move(const Position& target) const
{
	if (!Piece::is_valid_move(target))
		return false;

	// Valid moves are (n, n), where 8 > n > 0
	auto diff_pos = Position::abs_difference(position.current, target);
	if (diff_pos.get_row() != diff_pos.get_column())
		return false;

	return true;
}

void Bishop::move(const Position& target)
{
	if (!is_valid_move(target))
		throw DomainException("The move is invalid.");

	Piece::move(target);
}
