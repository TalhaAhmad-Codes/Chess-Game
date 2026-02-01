#include "DomainException.hpp"

using namespace Shield;

/*// Domain Exception class -- Implementation //*/

// Constructor
DomainException::DomainException(const std::string& message) : std::runtime_error(message) {}
