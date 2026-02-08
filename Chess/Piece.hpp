#pragma once

#include "PieceEnums.hpp"
#include "PiecePosition.hpp"
#include "ValidationResult.hpp"

namespace Entity
{
	// The base class for all kind of chess pieces
	class Piece
	{
	protected:
		// Attributes
		bool is_moved, is_alive;
		Interface::PieceType type;
		Interface::PieceGroup group;
		Interface::PiecePosition position;

		// Method - Move validator
		bool is_valid_move(const Utils::Position&) const;

		// Method - Guard against NONE group
		void against_none_group(Interface::PieceGroup&);

	public:
		// Constructors
		Piece(Interface::PieceType, Interface::PieceGroup, bool = false, bool = true);
		Piece(Interface::PieceType, Interface::PieceGroup, const Utils::Position&, bool = false, bool = true);

		// Getters
		Utils::Position get_position() const;
		Interface::PieceType get_type();
		Interface::PieceGroup get_group();
		bool moved() const;
		bool alive() const;

		// Method - Move the piece
		Utils::ValidationResult move(const Utils::Position&);
		void undo();	// Undo the piece

		// Method - Display piece information
		void display_info();
	};
}
