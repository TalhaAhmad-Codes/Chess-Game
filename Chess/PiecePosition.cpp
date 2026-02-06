#include "PiecePosition.hpp"

using namespace Interface;
using namespace Utils;
using namespace std;

/*// Piece Position structure -- Functions' Implementation //*/

// Constructor
PiecePosition::PiecePosition() {}

// Getters
Position PiecePosition::get_current() const
{
	return current;
}

Position PiecePosition::get_previous()
{
	if (!previous_moves.empty())
	{
		auto position = previous_moves.top();
		previous_moves.pop();
		return position;
	}

	return current;
}

// Method - Movement
void PiecePosition::move(const Position& target)
{
	// Move the piece and store position to the undo stack
	current = target;
	previous_moves.push(current);
}

// Destructor
PiecePosition::~PiecePosition()
{
	while (!previous_moves.empty())
		previous_moves.pop();
}
