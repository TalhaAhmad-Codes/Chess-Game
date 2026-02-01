#include "Name.hpp"

using namespace ValueObject;

/*// Name class -- Implementation //*/

// Constructor
Name::Name(std::string name)
{
	value = name;
}

// Getter
std::string Name::get()
{
	return value;
}
