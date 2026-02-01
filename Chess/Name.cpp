#include "Name.hpp"
#include "Guard.hpp"
#include "Functions.hpp"

using namespace ValueObject;

/*// Name class -- Implementation //*/

// Constructor
Name::Name(std::string name)
{
	Shield::Guard::against_null_or_whitespace(name, "Name");

	value = Utils::Functions::trim(name);
}

// Getter
std::string Name::get() const
{
	return value;
}
