#include "SuperTrap.hpp"

SuperTrap::~SuperTrap()
{
    std::cout << "SUPERTRAP2000 " << this->_name << " died. How?" << std::endl;
}

void SuperTrap::intializeDefaultValue()
{
    this->_HP = FragTrap::_HP;
    this->_MaxHP = FragTrap::_MaxHP;
    this->_EP = NinjaTrap::_EP;
    this->_MaxEP = NinjaTrap::_MaxEP;
    this->_lvl = 1;
    this->_meleeDamage = NinjaTrap::_meleeDamage;
    this->_rangeDamage = FragTrap::_rangeDamage;
    this->_armorDamageReduction = FragTrap::_armorDamageReduction;
    this->_type = "SUPERTRAP2000";
}

SuperTrap::SuperTrap(SuperTrap &superTrap)
{
    this->_name = superTrap.getName();
    this->intializeDefaultValue();
    std::cout << "SUPERTRAP2000 " << this->_name << " CAME, RUN OUT OF HERE" << std::endl;
}

void SuperTrap::operator=(SuperTrap &superTrap)
{
    this->_name = superTrap.getName();
    std::cout << "Some SUPERTRAP got " << this->_name << " name" << std::endl;
}

SuperTrap::SuperTrap(std::string name)
{
    this->_name = name;
    this->intializeDefaultValue();
    std::cout << "SUPERTRAP2000 " << name << " CAME, RUN OUT OF HERE";
}

void SuperTrap::rangedAttack(std::string const &target)
{
    FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const &target)
{
    NinjaTrap::meleeAttack(target);
}