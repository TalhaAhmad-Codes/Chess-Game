#pragma once

#include <string>

namespace Utils
{
	class Functions
	{
	public:
		static std::string to_lower(std::string&);
		static std::string trim(std::string&);
		static bool is_null_or_whitespace(const std::string&);
	};
}
