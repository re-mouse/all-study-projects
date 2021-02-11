#include "Pony.hpp"

Pony::Pony(std::string name)
{
    this->name = name;
    std::cout << this->name << " arrived" << "\n";
}

Pony::~Pony()
{
    std::cout << this->name << " went to the skies" << "\n";
}