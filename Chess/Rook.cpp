#include "Rook.hpp"
#include "DomainException.hpp"

using namespace Utils;
using namespace Entity;
using namespace Shield;

/*// Rook class -- Implementation //*/

// Constructors
Rook::Rook(PieceGroup group, bool is_moved)
	: Piece(PieceType::Rook, group, is_moved) {}

Rook::Rook(PieceGroup group, const Position& position, bool is_moved)
	: Piece(PieceType::Rook, group, position, is_moved) {}

// Method - Move validation
bool Rook::is_valid_move(const Position& target)
{
	bool validity = Piece::is_valid_move(target);

	/*
	Valid moves are:
		A. (1, 0) to (7, 0)		// Vertical
		B. (0, 1) to (0, 7)		// Horizontal
	*/
	auto diff_pos = Position::abs_difference(position.current, target);
	int row = diff_pos.get_row(), column = diff_pos.get_column();

	if (row == 0)
	{
		if (column == 0 || column > 7)	// B
			validity = false;
	}
	else if (column == 0)
	{
		if (row == 0 || row > 7)	// A
			validity = false;
	}
	else
	{
		validity = false;
	}

	return validity;
}

// Method - Move the rook
void Rook::move(const Position& target)
{
	// In-valid move
	if (!is_valid_move(target))
		throw DomainException("The move is invalid.");

	// Move the piece
	Piece::move(target);
}
