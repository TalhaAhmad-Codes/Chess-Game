#pragma once

#include <string>

namespace Utils
{
	class Range
	{
	private:
		// Attributes
		int start, end;

	public:
		// Constructor
		Range(const int&, const int&);

		// Getters
		int get_start() const;
		int get_end() const;

		// Method - Get string format
		std::string to_string() const;
	};
}
