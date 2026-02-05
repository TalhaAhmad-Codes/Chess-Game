#pragma once

#include <unordered_map>
#include <vector>
#include "Piece.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "Position.hpp"

namespace Entity
{
	class PieceHandler
	{
	private:
		// Attributes
		std::vector<Piece*> pieces;

		// Methods - Get pieces at initial positions
		void init_pieces(PieceGroup, PieceType);

	public:
		// Constructor
		PieceHandler(std::vector<Piece*>* = nullptr);

		// Method - Initialize / Reset
		void initialize();

		// Methods - Get a piece from given position
		Piece* get_piece(const Position&);

		// Descturctor
		~PieceHandler();
	};
}
