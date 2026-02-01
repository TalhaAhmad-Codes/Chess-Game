#include "Functions.hpp"
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
	if (Utils::Functions::is_null_or_whitespace(value))
		throw DomainException(property + " can't be whitespace / empty.");
}

void Guard::against_regex_mismatch(const Utils::Pattern& pattern, const std::string& value)
{
	if (!Utils::Functions::is_regex_match(pattern.get_pattern(), value))
		throw DomainException(pattern.get_message());
}
