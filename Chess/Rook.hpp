#pragma once

#include "Piece.hpp"

namespace Entity
{
	class Rook : public Piece
	{
	private:
		// Method - Check for valid move
		bool is_valid_move(const Utils::Position&) const override;

	public:
		// Constructors
		Rook(PieceGroup, bool = false, bool = true);
		Rook(PieceGroup, const Utils::Position&, bool = false, bool = true);

		// Method - Move the rook
		void move(const Utils::Position&) override;
	};
}
