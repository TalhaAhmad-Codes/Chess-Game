#include "PiecePosition.hpp"

using namespace Interface;
using namespace Utils;
using namespace std;

/*// Piece Position structure -- Functions' Implementation //*/

// Constructor
PiecePosition::PiecePosition(Position* position)
{
	current = position;
}

// Getters
Position PiecePosition::get_current() const
{
	return *current;
}

Position PiecePosition::get_previous()
{
	if (!previous_moves.empty())
	{
		auto position = previous_moves.top();
		previous_moves.pop();
		return position;
	}

	return *current;
}

// Method - Movement
void PiecePosition::move(const Position& target, bool save_to_stack)
{
	// Move the piece and store position to the undo stack
	if (current != nullptr && save_to_stack)
		previous_moves.push(*current);
	
	current = new Position(target);
}

// Method - Get initial positions for piece
vector<Position> PiecePosition::initial_positions(PieceType type, PieceGroup group)
{
	vector<Position> positions;

	///> I'll add the logic soon!

	return positions;
}

// Destructor
PiecePosition::~PiecePosition()
{
	delete current;

	while (!previous_moves.empty())
		previous_moves.pop();
}
