#include "ClapTrap.hpp"

void ClapTrap::intializeDefaultValue()
{
    this->_HP = 100;
    this->_MaxHP = 100;
    this->_EP = 50;
    this->_MaxEP = 50;
    this->_lvl = 1;
    this->_meleeDamage = 20;
    this->_rangeDamage = 15;
    this->_armorDamageReduction = 3;
    this->_type = "ClapTrap";
}

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap came to this place" << std::endl;
    this->_name = "Unnamed";
    this->intializeDefaultValue();
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap came to this place" << std::endl;
    this->_name = name;
    this->intializeDefaultValue();
}

ClapTrap::~ClapTrap()
{
    std::cout << "Mothertrap been destroyed T_T. F"
    << std::endl;
}

void ClapTrap::rangedAttack(std::string const &target)
{
    std::cout << this->_type << " " << this->_name << " attacks "
    << target << " by shooting, causing " << this->_rangeDamage
    << " points of damage!" << std::endl;
}

void ClapTrap::meleeAttack(std::string const &target)
{
    std::cout << this->_type << " " << this->_name << " attacks "
    << target << " by beat with melee, causing " << this->_meleeDamage
    << " points of damage!" << std::endl;
}

void ClapTrap::operator=(ClapTrap &ClapTrap)
{
    this->_name = ClapTrap._name;
    std::cout << "Some " << this->_type << " got " << this->_name << " name" << std::endl;
}

std::string ClapTrap::getName(void)
{
    return (this->_name);
}

ClapTrap::ClapTrap(ClapTrap &ClapTrap)
{
    this->_name = ClapTrap._name;
    this->intializeDefaultValue();
    std::cout << this->_type << " " << this->_name << " was born"
    << std::endl;
}

void ClapTrap::printStatus()
{
    if (this->_HP > 0)
        std::cout << this->_type << " " << this->_name << " feels great at "
        << this->_HP << " HP" << std::endl;
    else
        std::cout << this->_type << " " << this->_name << " feels bad at "
        << this->_HP << " HP" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    amount -= this->_armorDamageReduction;
    if (amount < 0)
        amount = 0;
    std::cout << this->_type << " " << this->_name << " filled pain and got "
    << amount << " damage" << std::endl;
    this->_HP -= amount;
    if (this->_HP < 0)
        this->_HP = 0;
    this->printStatus();
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << this->_type << " " << this->_name <<
    " received new tasty food "
    << amount << " HP" << std::endl;
    this->_HP += amount;
    if (this->_HP > this->_MaxHP)
        this->_HP = this->_MaxHP;
    this->printStatus();
}