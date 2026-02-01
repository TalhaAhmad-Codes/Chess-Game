#include <regex>
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

bool Functions::is_null_or_whitespace(const std::string& value)
{
	return value.empty() ||
		std::all_of(value.begin(), value.end(),
			[](unsigned char c)
			{
				return std::isspace(c);
			});
}

bool Functions::is_regex_match(const std::string& pattern, const std::string& value)
{
	return std::regex_match(value, std::regex(pattern));
}
