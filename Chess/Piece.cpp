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
		throw DomainException("Undo-stack is empty");
	}

	auto position = previous_moves.top();
	//previous_moves.pop();
	return position;
}

void PiecePosition::move(const Position& target)
{
	/// Valid move case
	previous_moves.push(current);
	current = target;
}

/*// Piece class -- Implementation //*/

// Constructors
Piece::Piece(PieceType type, PieceGroup group, bool is_moved)
{
	this->type = type;
	this->group = group;
	this->is_moved = is_moved;
}

Piece::Piece(PieceType type, PieceGroup group, const Utils::Position& position, bool is_moved)
{
	this->type = type;
	this->group = group;
	this->is_moved = is_moved;
	this->position.current = position;
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

// Method - Validate move
bool Piece::is_valid_move(const Position& target)
{
	auto diff_pos = Position::abs_difference(position.current, target);
	return diff_pos.get_row() == diff_pos.get_column() && diff_pos.get_row() == 0;
}

// Method - Move the piece
void Piece::move(const Position& target)
{
	position.move(target);
	is_moved = true;
}
