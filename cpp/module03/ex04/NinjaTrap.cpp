#include "NinjaTrap.hpp"

void NinjaTrap::intializeDefaultValue()
{
    this->_HP = 60;
    this->_MaxHP = 60;
    this->_EP = 120;
    this->_MaxEP = 120;
    this->_lvl = 1;
    this->_meleeDamage = 60;
    this->_rangeDamage = 5;
    this->_armorDamageReduction = 0;
    this->_type = "NinjaTrap";
}

NinjaTrap::NinjaTrap()
{
    this->intializeDefaultValue();
    std::cout << "NinjaTrap arrived" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name)
{
    std::cout << "NinjaTrap " << name << " came to kick others asses" << std::endl;
    this->_name = name;
    this->intializeDefaultValue();
}

void NinjaTrap::ninjaShoebox(ScavTrap  & target)
{
    std::cout << this->_type << " " << this->_name << " tryed attack a " << target.getName() << ", but scav " << 
    "used his trashcan and avoided attack, then he attacked him with katana and dealed " << this->_meleeDamage << " damage" << std::endl;
}

void NinjaTrap::operator=(NinjaTrap &ninjaTrap)
{
    this->_name = ninjaTrap._name;
    std::cout << "Some NINJA got " << this->_name << " name" << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap & target)
{
    std::cout << this->_type << " " << this->_name << " tryed attack a " << target.getName() << ", but shuriken can't hit metal :(" << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap & target)
{
    std::cout << this->_type << " " << this->_name << " tryed attack " << target.getName() << " , why??" << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap & target)
{
    std::cout << this->_type << " " << this->_name << " attacked " << target.getName() << " with shuriken and dealed " << this->_rangeDamage << " damage" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
    std::cout << "Can no longer throw a single shuriken. F" << std::endl;
}

void NinjaTrap::rangedAttack(std::string const &target)
{
    std::cout << this->_type << " " << this->_name << " attacks "
    << target << " by throwed shuriken and dealed " << this->_rangeDamage
    << " points of damage!" << std::endl;
}

void NinjaTrap::meleeAttack(std::string const &target)
{
    std::cout << this->_type << " " << this->_name << " attacks "
    << target << " by katana, and dealed " << this->_meleeDamage
    << " points of damage!" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap &NinjaTrap)
{
    this->_name = NinjaTrap._name;
    this->intializeDefaultValue();
    std::cout << this->_type << " " << this->_name << " was born"
    << std::endl;
}
