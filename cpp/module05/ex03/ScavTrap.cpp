#include "ScavTrap.hpp"

void ScavTrap::intializeDefaultValue()
{
    this->_HP = 100;
    this->_MaxHP = 100;
    this->_EP = 50;
    this->_MaxEP = 50;
    this->_lvl = 1;
    this->_meleeDamage = 20;
    this->_rangeDamage = 15;
    this->_armorDamageReduction = 3;
    this->_type = "SCAV-TP";
}

ScavTrap::ScavTrap(std::string name)
{
    this->_name = name;
    this->intializeDefaultValue();
    std::cout << "SCAV-TP " << this->_name << " was born"
    << std::endl;
}

void ScavTrap::operator=(ScavTrap &ScavTrap)
{
    this->_name = ScavTrap._name;
    std::cout << "Some SCAV-TP got " << this->_name << " name" << std::endl;
}

void ScavTrap::rangedAttack(std::string const &target)
{
    std::cout << "SCAV-TP " << this->_name << " attacks "
    << target << " by shooting, causing " << this->_rangeDamage
    << " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target)
{
    std::cout << "SCAV-TP " << this->_name << " attacks "
    << target << " by beat with melee, causing " << this->_meleeDamage
    << " points of damage!" << std::endl;
}

void ScavTrap::challengeNewComer(std::string const & target)
{
    std::srand(time(NULL));
    std::string challenges[] = {" by laughing at him", " by insulting him", " by shouting at him",
    " by licking him", " by tickling him"};
    int challengeId = std::rand() % 5;
    std::cout << "SCAV-TP " << this->_name << " challenge "
    << target << challenges[challengeId] << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "SCAV-TP " << this->_name << " went to the junkyard"
    << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &ScavTrap)
{
    this->_name = ScavTrap._name;
    this->intializeDefaultValue();
    std::cout << "SCAV-TP " << this->_name << " was born"
    << std::endl;
}
