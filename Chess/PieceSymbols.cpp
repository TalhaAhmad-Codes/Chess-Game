#include "PieceSymbols.hpp"

using namespace Interface;

/*// PieceSymbol class -- Implementation //*/

// Get the symbol for piece
char PieceSymbol::get_symbol(PieceType type, PieceGroup group)
{
	char symbol = ' ';

	if (group == PieceGroup::NONE)
		return symbol;

	switch (type)
	{
		case PieceType::PAWN:
			symbol = (group == PieceGroup::WHITE) ? 'P' : 'p';
			break;

		case PieceType::BISHOP:
			symbol = (group == PieceGroup::WHITE) ? 'B' : 'b';
			break;

		case PieceType::ROOK:
			symbol = (group == PieceGroup::WHITE) ? 'R' : 'r';
			break;

		case PieceType::KNIGHT:
			symbol = (group == PieceGroup::WHITE) ? 'N' : 'n';
			break;

		case PieceType::QUEEN:
			symbol = (group == PieceGroup::WHITE) ? 'Q' : 'q';
			break;

		case PieceType::KING:
			symbol = (group == PieceGroup::WHITE) ? 'K' : 'k';
			break;
	}

	return symbol;
}
