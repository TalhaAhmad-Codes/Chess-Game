#pragma once

#include <string>

namespace Shield
{
	class Guard
	{
	public:
		static void against_zero_or_less(const int&, const std::string&);
		static void against_zero(const int&, const std::string&);
		static void against_negative(const int&, const std::string&);
		static void against_null_or_whitespace(const std::string&, const std::string&);
	};
}
