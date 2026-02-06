#pragma once

#include <string>
#include "Range.hpp"

namespace Utils
{
	class Position
	{
	private:
		// Attributes
		int row, column;

	public:
		// Constructors
		Position();
		Position(const int& row, const int& column);
		Position(const Position&);

		// Getters & Setters
		int get_row() const;
		int get_column() const;
		Range get_range() const;

		void set_row(const int&);
		void set_column(const int&);

		// Methods - Operator overloading
		Position operator +(const Position&);
		Position operator -(const Position&);
		bool operator ==(const Position&);
		bool operator !=(const Position&);

		// Method - Get absolute difference
		static Position abs_difference(const Position&, const Position&);

		// Method - Display position - for debugging
		void display(const std::string& message);
	};
}
