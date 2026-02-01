#include "Name.hpp"
#include "Guard.hpp"
#include "Functions.hpp"
#include "Regex.hpp"

using namespace ValueObject;

/*// Name class -- Implementation //*/

// Constructors
Name::Name() {}
Name::Name(std::string name)
{
	name = Utils::Functions::trim(name);
	Shield::Guard::against_regex_mismatch(Utils::Regex::Name(), name);

	value = name;
}

// Getter
std::string Name::get() const
{
	return value;
}
