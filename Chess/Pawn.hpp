#pragma once

#include "Piece.hpp"

namespace Entity
{
	class Pawn : public Piece
	{
	public:
		// Constructors
		Pawn(PieceGroup, bool = false);
		Pawn(PieceGroup, const Utils::Position&, bool = false);

		// Method - Promote the piece
		void promote(PieceType);

		// Method - Move the piece
		void move(const Utils::Position&) override;
	};
}
