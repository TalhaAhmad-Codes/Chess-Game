#include "Pawn.hpp"
#include "DomainException.hpp"

using namespace Entity;
using namespace Utils;
using namespace Shield;

/*// Pawn class -- Implementation //*/

// Constructors
Pawn::Pawn(PieceGroup group, bool is_moved) : Piece(PieceType::Pawn, group, std::vector<Position>{
		Position(1, 0), Position(1, 1), Position(2, 0)
	})
{
	this->is_moved = is_moved;
}

Pawn::Pawn(PieceGroup group, const Position& position, bool is_moved) : Piece(PieceType::Pawn, group, position, std::vector<Position>{
	Position(1, 0), Position(1, 1), Position(2, 0)
})
{
	this->is_moved = is_moved;
}

// Method - Check for enpassant
void Pawn::check_en_passant(bool piece_exists_at_target, Utils::Position& difference)
{
	if (position.legal_moves.size() > 1)
	{
		if (piece_exists_at_target)
		{
			en_passant = difference == position.legal_moves[1];
		}
	}

	// Raise exception on illegal en-passant move
	if (!en_passant)
	{
		throw DomainException("En-passant is not possible.");
	}
}

// Method - Move the piece
void Pawn::move(const Utils::Position& target)
{
	// Abs-Difference position
	auto diff_pos = Position::abs_difference(position.current, target);

	// Check if 1st move is double box
	if (position.legal_moves.size() == 3)
		double_box_move = diff_pos == position.legal_moves[2];

	// Move the piece
	Piece::move(target);

	// Removing some of legal moves
	if (is_moved)
	{
		// Two blocks move
		if (position.legal_moves.size() == 3)
			position.legal_moves.pop_back();

		// En-passant move
		if (position.legal_moves.size() == 2)
		{
			if (!double_box_move)
				position.legal_moves.pop_back();
		}
	}
}

// Method - Promote the pawn
Piece Pawn::promote(PieceType type)
{
	if (position.current.get_row() == 0 && group == PieceGroup::White ||
		position.current.get_row() == 7 && group == PieceGroup::Black)
	{
		switch (type)
		{
			case PieceType::Bishop:
				break;

			case PieceType::Knight:
				break;

			case PieceType::Rook:
				break;

			case PieceType::Queen:
				break;

			default:
				throw DomainException("Invalid type selection for promotion.");
		}
	}
	else
	{
		throw DomainException("Pawn can't be promoted.");
	}
}
