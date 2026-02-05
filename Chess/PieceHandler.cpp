#include "PieceHandler.hpp"

using namespace Entity;
using namespace Utils;
using namespace std;

/*// Bishop class -- Implementation //*/

// Constructor
PieceHandler::PieceHandler(std::vector<Piece*>* pieces)
{
	if (pieces != nullptr)
		this->pieces = *pieces;
}

// Methods - Get pieces at initial positions
void PieceHandler::init_pieces(PieceGroup group, PieceType type)
{
	// Position initialization
	int row = (group == PieceGroup::WHITE) ? 0 : 7, column, columns[2];
	if (type == PieceType::PAWN)	// Pawn case
		row += (group == PieceGroup::WHITE) ? 1 : -1;

	// Piece Initialization
	if (type == PieceType::PAWN)
	{
		for (int c = 0; c < 8; c++)
		{
			Piece* pawn = new Pawn(group, Position(row, c));
			pieces.push_back(pawn);
		}
	}

	else if (type == PieceType::BISHOP)
	{
		columns[0] = 2;
		columns[1] = 5;
		for (auto&& column : columns)
		{
			Piece* bishop = new Bishop(group, Position(row, column));
			pieces.push_back(bishop);
		}
	}
		

	else if (type == PieceType::ROOK)
	{
		columns[0] = 0;
		columns[1] = 7;
		for (auto&& column : columns)
		{
			Piece* rook = new Rook(group, Position(row, column));
			pieces.push_back(rook);
		}
	}

	else if (type == PieceType::KNIGHT)
	{
		columns[0] = 1;
		columns[1] = 6;
		for (auto&& column : columns)
		{
			Piece* knight = new Knight(group, Position(row, column));
			pieces.push_back(knight);
		}
	}

	else if (type == PieceType::QUEEN)
	{
		column = 3;
		Piece* queen = new Queen(group, Position(row, column));
		pieces.push_back(queen);
	}

	else if (type == PieceType::KING)
	{
		column = 4;
		Piece* king = new King(group, Position(row, column));
		pieces.push_back(king);
	}
}

// Method - Initialize / Reset
void PieceHandler::initialize()
{
	// Groups and Types of pieces
	PieceGroup groups[] = { PieceGroup::WHITE, PieceGroup::BLACK };
	PieceType types[] = { PieceType::PAWN, PieceType::BISHOP, PieceType::ROOK, PieceType::KNIGHT, PieceType::QUEEN, PieceType::KING };

	// Clear the pieces' set
	this->pieces.clear();

	// Initializing the piece handler
	for (auto&& group : groups)
		for (auto&& type : types)
			init_pieces(group, type);
}

// Destructor
PieceHandler::~PieceHandler()
{
	pieces.clear();
}
