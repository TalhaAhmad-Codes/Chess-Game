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

// Method - Move the piece
void Pawn::move(const Utils::Position& target)
{
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
			//// Checking if en_passant is eligible
			//check_for_en_passant();

			//// Removing the en-passant move
			//if (!en_passant)
			//	position.legal_moves.pop_back();
		}
	}
}
