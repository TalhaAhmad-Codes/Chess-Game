#pragma once

#include <stack>
#include <vector>
#include "Position.hpp"

namespace Entity
{
	enum PieceType
	{
		Pawn, Bishop, Rook, Knight, Queen, King
	};

	enum PieceGroup
	{
		White, Black
	};

	struct PiecePosition
	{
		// Attributes
		Utils::Position current;					// Current position of the chess piece
		std::stack<Utils::Position> previous_moves;		// To support undo feature
		std::vector<Utils::Position> legal_moves;	// To hold only legal moves for the chess piece

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

	public:
		// Constructors
		Piece(PieceType, PieceGroup, std::vector<Utils::Position>, bool = false);
		Piece(PieceType, PieceGroup, const Utils::Position&, std::vector<Utils::Position>, bool = false);

		// Getters
		Utils::Position get_position() const;
		PieceType get_type() const;
		PieceGroup get_group() const;
		bool moved() const;

		// Method - Move the piece
		virtual void move(const Utils::Position&);
	};
}
