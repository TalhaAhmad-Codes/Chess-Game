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
	auto difference = to - from, current = from;
	int row = difference.get_row(), column = difference.get_column(),
		row_offset = (row > 0) ? 1 : -1, column_offset = (column > 0) ? 1 : -1;
	
	// Get the path
	vector<Position> path;
	while (current != to)
	{
		current = current + Position(row_offset, column_offset);
		path.push_back(current);
	}

	return path;
}

vector<Position> PathMoveValidator::get_bishop_path(Position& from, Position& to)
{
	// Guard against negative values
	from.against_negative_value();
	to.against_negative_value();

	// Calculate difference
	auto difference = to - from, current = from;
	int row = difference.get_row(), column = difference.get_column(),
		row_offset = (row > 0) ? 1 : -1, column_offset = (column > 0) ? 1 : -1;
	
	// Get the path
	vector<Position> path;
	while (current != to)
	{
		current = current + Position(row_offset, column_offset);
		path.push_back(current);
	}

	return path;
}

vector<Position> PathMoveValidator::get_rook_path(Position& from, Position& to)
{
	// Guard against negative values
	from.against_negative_value();
	to.against_negative_value();

	// Calculate difference
	auto difference = to - from, current = from;
	int row = difference.get_row(), column = difference.get_column(),
		row_offset = (row == 0) ? 0 : (row > 0) ? 1 : - 1, column_offset = (column == 0) ? 0 : (column > 0) ? 1 : -1;
	
	// Get the path
	vector<Position> path;
	while (current != to)
	{
		current = current + Position(row_offset, column_offset);
		path.push_back(current);
	}

	return path;
}

vector<Position> PathMoveValidator::get_knight_path(Position& from, Position& to)
{
	// Guard against negative values
	from.against_negative_value();
	to.against_negative_value();

	// Get path
	vector<Position> path;
	path.push_back(to);

	return path;
}

vector<Position> PathMoveValidator::get_queen_path(Position& from, Position& to)
{
	// Guard against negative values
	from.against_negative_value();
	to.against_negative_value();

	// Calculate difference
	auto difference = to - from, current = from;
	int row = difference.get_row(), column = difference.get_column(),
		row_offset = (row == 0) ? 0 : (row > 0) ? 1 : -1, column_offset = (column == 0) ? 0 : (column > 0) ? 1 : -1;

	// Get path
	vector<Position> path;
	while (current != to)
	{
		current = current + Position(row_offset, column_offset);
		path.push_back(current);
	}

	return path;
}

vector<Position> PathMoveValidator::get_king_path(Position& from, Position& to)
{
	return get_knight_path(from, to);
}

ValidationResult PathMoveValidator::is_path_clear(Position& from, Position& to, Board& board, PieceType type)
{
	// Get the path for specific piece
	vector<Position> path;

	if (board.get_cell(from)->is_empty())
		return ValidationResult::EMPTY_CELL;

	switch (type)
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
	}

	// Check the path
	int piece_count = 0;
	for (auto&& position : path)
	{
		auto cell = board.get_cell(position);
		
		if (!cell->is_empty())
			piece_count++;
	}

	return (piece_count > 1) ? ValidationResult::UNCLEAR_PATH : ValidationResult::OK;
}
