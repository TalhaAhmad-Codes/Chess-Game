#pragma once

#include "Piece.hpp"

namespace Entity
{
	class Queen : public Piece
	{
	private:
		bool is_valid_move(const Utils::Position&) const override;

	public:
		Queen(PieceGroup, bool = false, bool = true);
		Queen(PieceGroup, const Utils::Position&, bool = false, bool = true);

		void move(const Utils::Position&) override;
	};
}
