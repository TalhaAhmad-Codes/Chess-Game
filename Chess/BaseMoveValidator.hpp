#pragma once

#include "Position.hpp"
#include "PieceEnums.hpp"

namespace Logic
{
	class BaseMoveValidator
	{
		static bool is_in_range(const Utils::Position&);
		static bool base_validation(const Utils::Position&, const Utils::Position&);
	public:
		static bool pawn_validation(const Utils::Position&, const Utils::Position&, Interface::PieceGroup);
		static bool bishop_validation(const Utils::Position&, const Utils::Position&);
		static bool rook_validation(const Utils::Position&, const Utils::Position&);
		static bool knight_validation(const Utils::Position&, const Utils::Position&);
		static bool queen_validation(const Utils::Position&, const Utils::Position&);
		static bool king_validation(const Utils::Position&, const Utils::Position&);
	};
}
