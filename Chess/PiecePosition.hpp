#pragma once

#include <stack>
#include <vector>
#include "Position.hpp"
#include "PieceEnums.hpp"

namespace Interface
{
	class PiecePosition
	{
	private:
		// Attributes
		Utils::Position* current;						// Current position of the chess piece
		std::stack<Utils::Position> previous_moves;		// To support undo feature

	public:
		// Constructor
		PiecePosition(Utils::Position* = nullptr);

		// Getters
		Utils::Position get_previous();	// Get recent position from the stack
		Utils::Position get_current() const;	// Get the current position of the piece
		static std::vector<Utils::Position> initial_positions(Interface::PieceType, Interface::PieceGroup);

		// Method - Movement
		void move(const Utils::Position&, bool = true);		// Move the piece to a targated position

		// Destructor
		~PiecePosition();
	};
}
