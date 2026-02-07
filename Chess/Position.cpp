#include <cmath>
#include <iostream>
#include "Position.hpp"
#include "Guard.hpp"
#include "Regex.hpp"

using namespace std;
using namespace Utils;
using namespace Shield;

/*// Position class -- Implementation //*/

// Constructors
Position::Position()
{
	row = column = 0;
}

Position::Position(const int& row, const int& column)
{
	set_row(row);
	set_column(column);
}

Position::Position(const Position& position)
{
	set_row(position.get_row());
	set_column(position.get_column());
}

// Getters & Setters
int Position::get_row() const
{
	return row;
}

int Position::get_column() const
{
	return column;
}

Range Position::get_range() const
{
	return Range(-7, 7);
}

void Position::set_row(const int& row)
{
	Guard::against_out_of_range(get_range(), row, "Row");

	this->row = row;
}

void Position::set_column(const int& column)
{
	Guard::against_out_of_range(get_range(), column, "Column");

	this->column = column;
}

// Operator overloading

Position Position::operator+(const Position& other)
{
	return Position(row + other.get_row(), column + other.get_column());
}

Position Position::operator-(const Position& other)
{
	return Position(row - other.get_row(), column - other.get_column());
}

bool Position::operator==(const Position& other)
{
	return row == other.get_row() && column == other.get_column();
}

bool Position::operator!=(const Position& other)
{
	return !(*this == other);
}

// Method - Absolute difference
Position Position::abs_difference(const Position& left, const Position& right)
{
	int row = std::abs(left.get_row() - right.get_row()),
		column = std::abs(left.get_column() - right.get_column());

	return Position(row, column);
}

// Method - Convert Label -> Position
Position Position::to_position(const string& label)
{
	Guard::against_regex_mismatch(Regex::LabelPosition(), label);

	// Getting row and column
	int row = label[1], column = label[0];

	// Calculating values
	row -= '1'; column -= 'a';

	// Creating a position object
	return Position(row, column);
}

string Position::to_labeled_position(const Position& position)
{
	position.against_negative_value();

	char row = '1', column = 'a';
	row += position.get_row();
	column += position.get_column();

	string label = string(column, 1) + string(row, 1);
	return label;
}

// Method - Guard against negative value
void Position::against_negative_value() const
{
	Guard::against_negative(row, "Row");
	Guard::against_negative(column, "Column");
}

// Method - Display position
void Position::display(const string& message)
{
	cout << message << '(' << row << ", " << column << ')' << endl;
}
