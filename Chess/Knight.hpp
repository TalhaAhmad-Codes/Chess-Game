#pragma once

#include "Piece.hpp"

namespace Entity
{
	class Knight : public Piece
	{
	private:
		bool is_valid_move(const Utils::Position&) const override;

	public:
		Knight(PieceGroup, bool = false, bool = true);
		Knight(PieceGroup, const Utils::Position&, bool = false, bool = true);

		void move(const Utils::Position&) override;
	};
}
