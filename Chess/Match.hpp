#pragma once

#include "Board.hpp"
#include "Player.hpp"
#include "PathMoveValidator.hpp"

namespace Logic
{
	class Match
	{
	private:
		// Attributes
		Entity::Player* players[2];
		Entity::Board* board;
		int turn;

	public:
		bool game_over;

		// Constructors
		Match(Entity::Player*, Entity::Player*);
		Match(Entity::Player*, Entity::Player*, Entity::Board*, int = 0);

		// Getter
		int get_turn() const;

		// Method - Move piece
		Utils::ValidationResult move_piece(Utils::Position&, Utils::Position&);

		// Method - Update turn
		void update_turn();

		// Destructor
		~Match();
	};
}
