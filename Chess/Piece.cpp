#include <iostream>
#include "DomainException.hpp"
#include "Piece.hpp"
#include "BaseMoveValidator.hpp"

using namespace std;
using namespace Entity;
using namespace Utils;
using namespace Shield;
using namespace Interface;
using namespace Logic;


/*// Piece class -- Implementation //*/

// Constructors
Piece::Piece(PieceType type, PieceGroup group, bool is_moved, bool is_alive)
{
	this->type = type;
	this->group = group;
	this->is_moved = is_moved;
	this->is_alive = is_alive;
}

Piece::Piece(PieceType type, PieceGroup group, const Utils::Position& position, bool is_moved, bool is_alive)
{
	this->type = type;
	this->group = group;
	this->is_moved = is_moved;
	this->position.move(position);
	this->is_alive = is_alive;
}

// Getters
Position Piece::get_position() const
{
	return position.get_current();
}

PieceType Piece::get_type()
{
	return type;
}

PieceGroup Piece::get_group()
{
	return group;
}

bool Piece::moved() const
{
	return is_moved;
}

bool Piece::alive() const
{
	return is_alive;
}

// Method - Validate move
bool Piece::is_valid_move(const Position& target) const
{
	bool validity = true;
	auto current = get_position();

	switch (type)
	{
		case PieceType::PAWN:
			validity = BaseMoveValidator::pawn_validation(current, target, group);
			break;
		case PieceType::BISHOP:
			validity = BaseMoveValidator::bishop_validation(current, target);
			break;
		case PieceType::ROOK:
			validity = BaseMoveValidator::rook_validation(current, target);
			break;
		case PieceType::KNIGHT:
			validity = BaseMoveValidator::knight_validation(current, target);
			break;
		case PieceType::QUEEN:
			validity = BaseMoveValidator::queen_validation(current, target);
			break;
		case PieceType::KING:
			validity = BaseMoveValidator::king_validation(current, target);
			break;
	}

	return validity;
}

// Method - Move the piece
void Piece::move(const Position& target)
{
	if (!is_valid_move(target))
		throw DomainException("The move is invalid.");

	position.move(target);
	is_moved = true;
}

// Method - Undo the piece
void Piece::undo()
{
	// Updated soon!
}

// Display piece info
void Piece::display_info()
{
	// Variables
	string group = (this->group == PieceGroup::WHITE) ? "White" : "Black",
	//PAWN = 0, BISHOP, ROOK, KNIGHT, QUEEN, KING
	type[] = {"Pawn", "Bishop", "Rook", "Knight", "Queen", "King"},
	moved = (is_moved) ? "True" : "False";

	// Displaying data
	cout << "\n********** Piece Information **********" << endl;
	cout << "Group:\t\t" << group << endl;
	cout << "Type:\t\t" << type[get_type()] << endl;
	get_position().display("Position:\t");
	cout << "Moved:\t\t" << moved << endl;
}
