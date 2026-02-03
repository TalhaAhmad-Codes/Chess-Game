#pragma once

#include "Piece.hpp"

namespace Entity
{
	class Rook : public Piece
	{
	private:
		// Method - Check for valid move
		bool is_valid_move(const Utils::Position&) override;

	public:
		// Constructors
		Rook(PieceGroup, bool = false);
		Rook(PieceGroup, const Utils::Position&, bool = false);

		// Method - Move the rook
		void move(const Utils::Position&) override;
	};
}
