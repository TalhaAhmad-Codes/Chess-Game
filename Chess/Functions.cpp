#include <cctype>

#include "Functions.hpp"

using namespace Utils;

/*// Functions class -- Implementation //*/

std::string Functions::to_lower(std::string& value)
{
	std::string result = "";

	for (auto&& chr : value)
	{
		result += std::tolower(chr);
	}

	return result;
}

std::string Functions::trim(std::string& value)
{
	size_t start = 0;
	size_t end = value.size();

	// left trim
	while (start < end && std::isspace(static_cast<unsigned char>(value[start])))
	{
		++start;
	}

	// right trim
	while (end > start && std::isspace(static_cast<unsigned char>(value[end - 1])))
	{
		--end;
	}

	return value.substr(start, end - start);
}
