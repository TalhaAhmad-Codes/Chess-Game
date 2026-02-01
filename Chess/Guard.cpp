#include <algorithm>
#include <cctype>

#include "Guard.hpp"
#include "DomainException.hpp"

using namespace Shield;

/*// Guard class -- Implementation //*/

void Guard::against_zero_or_less(const int& value, const std::string& property)
{
	if (value <= 0)
		throw DomainException(property + " can't be zero or negative.");
}

void Guard::against_zero(const int& value, const std::string& property)
{
	if (value == 0)
		throw DomainException(property + " can't be zero.");
}

void Guard::against_negative(const int& value, const std::string& property)
{
	if (value < 0)
		throw DomainException(property + " can't be negative.");
}

void Guard::against_null_or_whitespace(const std::string& value, const std::string& property)
{
	bool has_whitespace = value.empty() ||
		std::all_of(value.begin(), value.end(),
			[](unsigned char c)
			{
				return std::isspace(c);
			});

	if (has_whitespace)
		throw DomainException(property + " can't be whitespace / empty.");
}
