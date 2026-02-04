#pragma once

#include "Piece.hpp"

namespace Entity
{
	class Bishop : public Piece
	{
	private:
		bool is_valid_move(const Utils::Position&) const override;

	public:
		Bishop(PieceGroup, bool = false);
		Bishop(PieceGroup, const Utils::Position&, bool = false);

		void move(const Utils::Position&) override;
	};
}
