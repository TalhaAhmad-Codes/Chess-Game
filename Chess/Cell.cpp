#include "Cell.hpp"

using namespace Entity;
using namespace Utils;


/*// Cell class -- Implementation //*/

// Constructor
Cell::Cell(Piece* piece)
{
	this->piece = piece;
}

// Getters
Piece* Cell::get_piece()
{
	return piece;
}

bool Cell::is_empty() const
{
	return piece == nullptr;
}

// Methods
void Cell::make_empty()
{
	piece = nullptr;
}

void Cell::place_piece(Piece* piece)
{
	this->piece = piece;
}

// Destructor
Cell::~Cell()
{
	delete piece;
}
