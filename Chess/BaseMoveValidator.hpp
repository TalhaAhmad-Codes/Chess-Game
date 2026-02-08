#pragma once

#include "Position.hpp"
#include "PieceEnums.hpp"
#include "ValidationResult.hpp"

namespace Logic
{
	class BaseMoveValidator
	{
		static Utils::ValidationResult is_in_range(const Utils::Position&);
		static Utils::ValidationResult base_validation(const Utils::Position&, const Utils::Position&);
	public:
		static Utils::ValidationResult pawn_validation(const Utils::Position&, const Utils::Position&, Interface::PieceGroup);
		static Utils::ValidationResult bishop_validation(const Utils::Position&, const Utils::Position&);
		static Utils::ValidationResult rook_validation(const Utils::Position&, const Utils::Position&);
		static Utils::ValidationResult knight_validation(const Utils::Position&, const Utils::Position&);
		static Utils::ValidationResult queen_validation(const Utils::Position&, const Utils::Position&);
		static Utils::ValidationResult king_validation(const Utils::Position&, const Utils::Position&);
	};
}
