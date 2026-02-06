#pragma once

#include "Piece.hpp"

namespace Entity
{
	class Cell
	{
	private:
		Piece* piece;

	public:
		// Constructor
		Cell(Piece* = nullptr);

		// Getters
		Piece* get_piece();
		bool is_empty() const;

		// Method - Make cell empty
		void make_empty();

		// Method - Place a piece
		void place_piece(Piece* piece);

		// Destructor
		~Cell();
	};
}
