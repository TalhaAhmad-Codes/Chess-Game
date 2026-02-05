#pragma once

#include "Piece.hpp"

namespace Entity
{
	class Pawn : public Piece
	{
	private:
		// Method - Check for valid move
		bool is_valid_move(const Utils::Position&) const override;

	public:
		// Constructors
		Pawn(PieceGroup, bool = false, bool = true);
		Pawn(PieceGroup, const Utils::Position&, bool = false, bool = true);
		
		// Method - Check if pawn can be promoted or not
		bool can_be_promoted() const;

		// Method - Move the pawn
		void move(const Utils::Position&) override;
	};
}
