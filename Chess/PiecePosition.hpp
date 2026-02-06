#pragma once

#include <stack>
#include "Position.hpp"

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

		// Method - Movement
		void move(const Utils::Position&, bool = true);		// Move the piece to a targated position

		// Destructor
		~PiecePosition();
	};
}
