#include "DomainException.hpp"
#include "Piece.hpp"

using namespace Entity;
using namespace Utils;
using namespace Shield;

/*// PiecePosition structure -- Functions' Implementation //*/

Position PiecePosition::get_previous() const
{
	if (previous_moves.empty())
	{
		throw DomainException("Undo stack is empty");
	}

	auto position = previous_moves.top();
	//previous_moves.pop();
	return position;
}

void PiecePosition::move(const Position& target)
{
	// Get absolute difference for the position
	auto position = Position::abs_difference(current, target);
	bool is_valid = false;

	// Check if the move is legal or not
	for (auto&& move : legal_moves)
	{
		if (position == move)	// Match found!
		{
			is_valid = true; break;
		}
	}

	// In-valid move case
	if (!is_valid)
		throw DomainException("The move is invalid!");

	// Valid move case
	previous_moves.push(current);
	current = position;
}

/*// Piece class -- Implementation //*/

// Constructors
Piece::Piece(PieceType type, PieceGroup group, std::vector<Utils::Position> legal_moves, bool is_moved)
{
	this->type = type;
	this->group = group;
	this->is_moved = is_moved;
	position.legal_moves = legal_moves;
}

Piece::Piece(PieceType type, PieceGroup group, const Utils::Position& position, std::vector<Utils::Position> legal_moves, bool is_moved)
{
	this->type = type;
	this->group = group;
	this->is_moved = is_moved;
	this->position.current = position;
	this->position.legal_moves = legal_moves;
}

// Getters
Position Piece::get_position() const
{
	return position.current;
}

PieceType Piece::get_type() const
{
	return type;
}

PieceGroup Piece::get_group() const
{
	return group;
}

bool Piece::moved() const
{
	return is_moved;
}

// Method - Move the piece

void Piece::move(const Position& target)
{
	position.move(target);
	is_moved = true;
}
