#include "Range.hpp"

using namespace Utils;

/*// Range class -- Implementation //*/

// Constructor
Range::Range(const int& start, const int& end) : start(start), end(end) {}

// Getters
int Range::get_start() const
{
	return start;
}

int Range::get_end() const
{
	return end;
}

// Method - To string
std::string Range::to_string() const
{
	return "(" + std::to_string(start) + ", " + std::to_string(end) + ")";
}
