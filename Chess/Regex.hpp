#pragma once

#include <string>

namespace Utils
{
	class Pattern
	{
	private:
		// Attributes
		std::string value;
		std::string message;

	public:
		// Constructors
		Pattern();
		Pattern(const std::string&, const std::string&);

		// Getters
		std::string get_pattern() const;
		std::string get_message() const;
	};

	class Regex
	{
	public:
		static Utils::Pattern Name();
	};
}
