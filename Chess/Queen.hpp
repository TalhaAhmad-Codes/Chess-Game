#pragma once

#include "Piece.hpp"

namespace Entity
{
	class Queen : public Piece
	{
	private:
		bool is_valid_move(const Utils::Position&) const override;

	public:
		Queen(PieceGroup, bool = false);
		Queen(PieceGroup, const Utils::Position&, bool = false);

		void move(const Utils::Position&) override;
	};
}
