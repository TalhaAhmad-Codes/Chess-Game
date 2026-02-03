#pragma once

#include <stack>
#include "Position.hpp"

namespace Entity
{
	enum PieceType
	{
		PAWN = 0, BISHOP, ROOK, KNIGHT, QUEEN, KING
	};

	enum PieceGroup
	{
		WHITE = 0, BLACK
	};

	struct PiecePosition
	{
		// Attributes
		Utils::Position current;					// Current position of the chess piece
		std::stack<Utils::Position> previous_moves;		// To support undo feature

		// Functions
		Utils::Position get_previous() const;	// Get recent position from the stack
		void move(const Utils::Position&);		// Move the piece to a targated position
	};

	// The base class for all kind of chess pieces
	class Piece
	{
	protected:
		// Attributes
		bool is_moved;
		PieceType type;
		PieceGroup group;
		PiecePosition position;

		// Method - Move validator
		virtual bool is_valid_move(const Utils::Position&);

	public:
		// Constructors
		Piece(PieceType, PieceGroup, bool = false);
		Piece(PieceType, PieceGroup, const Utils::Position&, bool = false);

		// Getters
		Utils::Position get_position() const;
		PieceType get_type() const;
		PieceGroup get_group() const;
		bool moved() const;

		// Method - Move the piece
		virtual void move(const Utils::Position&);

		// Method - Display piece information
		void display_info();
	};
}
