#pragma once

#include "Piece.hpp"

namespace Entity
{
	class King : public Piece
	{
	private:
		bool is_valid_move(const Utils::Position&) const override;

	public:
		King(PieceGroup, bool = false);
		King(PieceGroup, const Utils::Position&, bool = false);

		void move(const Utils::Position&) override;
	};
}
