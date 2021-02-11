#include "Brain.hpp"

std::string Brain::identify()
{
    std::stringstream s;
    s << std::hex << this;
    return (s.str());
}