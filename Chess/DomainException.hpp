#pragma once

#include <stdexcept>
#include <string>

namespace Shield
{
    class DomainException : public std::runtime_error
    {
    public:
        explicit DomainException(const std::string&);
    };
}
