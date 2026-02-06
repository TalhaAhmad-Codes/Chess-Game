#include "PathMoveValidator.hpp"

using namespace std;
using namespace Logic;
using namespace Utils;
using namespace Entity;
using namespace Interface;

/*// Path Move Validator class -- Implementation //*/

vector<Position> PathMoveValidator::get_pawn_path(Position& from, Position& to)
{
	// Guard against negative values
	from.against_negative_value();
	to.against_negative_value();

	// Calculate difference
	auto difference = to - from;
	int row = difference.get_row(), column = difference.get_column();
	vector<Position> path;

	// Double cell movement
	if (column == 0)
	{
		Position position;
		if (row == 2)
		{
			position = Position(from.get_row() + 1, from.get_column());
		}
		else if (row == -2)
		{
			position = Position(from.get_row() - 1, from.get_column());
		}
		path.push_back(position);
	}

	return path;
}

vector<Position> PathMoveValidator::get_bishop_path(Position& from, Position& to)
{
	// Guard against negative values
	from.against_negative_value();
	to.against_negative_value();

	// Calculate difference
	auto difference = to - from;
	int row = difference.get_row(), column = difference.get_column();
	vector<Position> path;

	return path;
}

bool PathMoveValidator::is_path_clear(Position& from, Position& to, Board& board, PieceType type)
{
	// Get the path for specific piece
	vector<Position> path;

	/*switch (type)
	{
		case PieceType::PAWN:
			path = get_pawn_path(from, to); break;

		case PieceType::BISHOP:
			path = get_bishop_path(from, to); break;

		case PieceType::ROOK:
			path = get_rook_path(from, to); break;

		case PieceType::KNIGHT:
			path = get_knight_path(from, to); break;

		case PieceType::QUEEN:
			path = get_queen_path(from, to); break;

		case PieceType::KING:
			path = get_king_path(from, to); break;
	}*/

	// Check the path
	for (auto&& position : path)
	{
		auto cell = board.get_cell(position);
		
		if (!cell->is_empty()) return false;
	}
	return true;
}
