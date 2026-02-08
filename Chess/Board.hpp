#pragma once

#include "Cell.hpp"
#include "ValidationResult.hpp"

namespace Entity
{
	class Board
	{
	private:
		Cell grid[8][8];

		// Methods - Clear the board and reset positions of all pieces
		void clear();
		void reset_pieces();

	public:
		// Constructor
		Board();

		// Getters
		Cell* get_cell(const Utils::Position&);
		bool is_empty(const Utils::Position&);
		Interface::PieceGroup get_piece_group(const Utils::Position&);

		// Method - Place a piece
		void place_piece(Piece*, const Utils::Position&);

		// Method - Move a piece from one position to another
		Utils::ValidationResult move_piece(Utils::Position&, Utils::Position&);

		// Method - Initialize / Reset the grid of the board
		void reset();

		// Method - Display --- Debugging purpose
		void display();
	};
}
