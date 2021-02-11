#include "Zombie.hpp"

Zombie::Zombie(){}

void Zombie::SetTypeAndName(std::string type, std::string name)
{
    this->_type = type;
    this->_name = name;
}

Zombie::Zombie(std::string name, std::string type)
{
    this->_name = name;
    this->_type = type;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " (" << this->_type << "): "  << "why(((" << "\n";
}

void Zombie::announce()
{
    std::cout << this->_name << " (" << this->_type << "): "  << "Brains????" << "\n";
}