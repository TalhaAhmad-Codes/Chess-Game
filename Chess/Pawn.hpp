#pragma once

#include "Piece.hpp"

namespace Entity
{
	class Pawn : public Piece
	{
	private:
		bool en_passant, double_box_move;

	public:
		// Constructors
		Pawn(PieceGroup, bool = false);
		Pawn(PieceGroup, const Utils::Position&, bool = false);

		// Method - Check for en-passant
		void check_en_passant(bool, Utils::Position&);
		
		// Method - Promote the piece
		Piece promote(PieceType);

		// Method - Move the piece
		void move(const Utils::Position&) override;
	};
}
