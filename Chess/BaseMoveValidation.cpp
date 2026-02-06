#include "BaseMoveValidator.hpp"
#include "DomainException.hpp"

using namespace Logic;
using namespace Utils;
using namespace Shield;
using namespace Interface;

/*// Simple Move Validator class -- Implementation //*/

// Check for board size range (non-negative)
bool BaseMoveValidator::is_in_range(const Position& position)
{
	bool validity = true;

	try
	{
		position.against_negative_value();
	}
	catch (const DomainException& ex)
	{
		validity = false;
	}

	return validity;
}

// Base move validation check
bool BaseMoveValidator::base_validation(const Position& from, const Position& to)
{
	// If piece doesn't move
	auto diff_pos = Position::abs_difference(from, to);
	if (diff_pos.get_row() == diff_pos.get_column() && diff_pos.get_row() == 0)
		return false;

	// Ensure the movement is inside board size range
	return is_in_range(from) && is_in_range(to);
}

// Move validation for Pawn
bool BaseMoveValidator::pawn_validation(const Position& from, const Position& to, PieceGroup group)
{
	// If failed basic validation
	if (!base_validation(from, to))
		return false;

	bool is_first_move = true;
	// Ensure pawn doesn't move backwards
	switch (group)
	{
		case PieceGroup::WHITE:
			if (to.get_row() < from.get_row()) return false;
			is_first_move = from.get_row() == 1;
			break;

		case PieceGroup::BLACK:
			if (to.get_row() > from.get_row()) return false;
			is_first_move = to.get_row() == 6;
			break;
	}

	// Check for pawn movement rules
	auto diff_pos = Position::abs_difference(from, to);
	int row = diff_pos.get_row(), column = diff_pos.get_column();

	if (column == 0)
	{
		if (row == 2)	// (2, 0)
		{
			if (!is_first_move) return false;
		}
		else if (row != 1)	// (1, 0)
			return false;
	}
	else if (column == 1)
	{
		if (row != 1)	// (1, 1)
			return false;
	}
	else
	{
		return false;
	}

	return true;
}

// Move validation for Bishop
bool BaseMoveValidator::bishop_validation(const Position& from, const Position& to)
{
	// If failed basic validation
	if (!base_validation(from, to))
		return false;

	// Check for bishop movement rules
	auto diff_pos = Position::abs_difference(from, to);
	int row = diff_pos.get_row(), column = diff_pos.get_column();

	if (row != column)	// (n, n) where 0 < n < 8
		return false;

	return true;
}

// Move validation for Rook
bool BaseMoveValidator::rook_validation(const Position& from, const Position& to)
{
	// If basic validation failed
	if (!base_validation(from, to))
		return false;

	// Validation for rook movement rules
	auto diff_pos = Position::abs_difference(from ,to);
	int row = diff_pos.get_row(), column = diff_pos.get_column();

	if (row != 0 && column != 0)	// (n, 0) and (0, n) where 0 < n < 8
		return false;

	return true;
}

// Move validation for Knight
bool BaseMoveValidator::knight_validation(const Position& from, const Position& to)
{
	// If basic validation failed
	if (!base_validation(from, to))
		return false;

	// Validation for knight movement rules
	auto diff_pos = Position::abs_difference(from, to);
	int row = diff_pos.get_row(), column = diff_pos.get_column();

	if (row == 2)
	{
		if (column != 1)	// (2, 1)
			return false;
	}
	else if (column == 2)
	{
		if (row != 1)	// (1, 2)
			return false;
	}
	else
	{
		return false;
	}

	return true;
}

// Move validation for Queen
bool BaseMoveValidator::queen_validation(const Position& from, const Position& to)
{
	// Combination of Bishop and Rook
	return bishop_validation(from, to) || rook_validation(from, to);
}

// Move validation for King
bool BaseMoveValidator::king_validation(const Position& from, const Position& to)
{
	// If basic validation failed
	if (!base_validation(from, to))
		return false;

	// Validation for king movement rules
	auto diff_pos = Position::abs_difference(from, to);
	int row = diff_pos.get_row(), column = diff_pos.get_column();

	if (row == column)
	{
		if (row != 1)	// (1, 1)
			return false;
	}
	else
	{
		if (row == 0 && column != 1)	// (0, 1)
			return false;
		else if (column == 0 && row != 1)	 // (1, 0)
			return false;
		else
			return false;
	}

	return true;
}
