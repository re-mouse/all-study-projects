#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

HumanB::HumanB(std::string name)
{
    this->_weapon = NULL;
    this->_name = name;
}

void HumanB::attack()
{
    std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}