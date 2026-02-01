#include "Regex.hpp"

using namespace Utils;

/*// Pattern class -- Implementation //*/

// Constructors
Pattern::Pattern() {}

Pattern::Pattern(const std::string& pattern, const std::string& message)
{
	value = pattern;
	this->message = message;
}

// Getters
std::string Pattern::get_pattern() const
{
	return value;
}

std::string Pattern::get_message() const
{
	return message;
}

/*// Regex class -- Implementation //*/

Pattern Regex::Name()
{
	return Pattern(
		"^[A-Za-z][A-Za-z0-9]{3,20}$",
		"Name can only contain alphanumeric characters and must start with an alphabet. Its size limit is from 3 to 20 characters."
	);
}
