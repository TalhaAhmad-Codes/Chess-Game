#pragma once

#include "Piece.hpp"

namespace Entity
{
	class Bishop : public Piece
	{
	private:
		bool is_valid_move(const Utils::Position&) const override;

	public:
		Bishop(PieceGroup, bool = false, bool = true);
		Bishop(PieceGroup, const Utils::Position&, bool = false, bool = true);

		void move(const Utils::Position&) override;
	};
}
