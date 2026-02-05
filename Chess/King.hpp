#pragma once

#include "Piece.hpp"

namespace Entity
{
	class King : public Piece
	{
	private:
		bool is_valid_move(const Utils::Position&) const override;

	public:
		King(PieceGroup, bool = false, bool = true);
		King(PieceGroup, const Utils::Position&, bool = false, bool = true);

		void move(const Utils::Position&) override;
	};
}
