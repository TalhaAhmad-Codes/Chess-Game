#pragma once

#include "ValidationResult.hpp"
#include "Board.hpp"

namespace Logic
{
	class PathMoveValidator
	{
	private:
		static std::vector<Utils::Position> get_pawn_path(Utils::Position&, Utils::Position&);
		static std::vector<Utils::Position> get_bishop_path(Utils::Position&, Utils::Position&);
		static std::vector<Utils::Position> get_rook_path(Utils::Position&, Utils::Position&);
		static std::vector<Utils::Position> get_knight_path(Utils::Position&, Utils::Position&);
		static std::vector<Utils::Position> get_queen_path(Utils::Position&, Utils::Position&);
		static std::vector<Utils::Position> get_king_path(Utils::Position&, Utils::Position&);
	public:
		static Utils::ValidationResult is_path_clear(Utils::Position&, Utils::Position&, Entity::Board&, Interface::PieceType);
	};
}
