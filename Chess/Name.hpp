#pragma once
#include <string>

namespace ValueObject
{
	class Name
	{
	private:
		// Attribute
		std::string value;

	public:
		// Constructor
		Name(std::string name);

		// Method - Getter
		std::string get();
	};
}
