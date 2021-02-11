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
}

ScavTrap::ScavTrap(std::string name)
{
    this->_name = name;
    this->intializeDefaultValue();
    std::cout << "SCAV-TP " << this->_name << " was born"
    << std::endl;
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

void ScavTrap::operator=(ScavTrap &ScavTrap)
{
    this->_name = ScavTrap._name;
    std::cout << "Some SCAV-TP got " << this->_name << " name" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &ScavTrap)
{
    this->_name = ScavTrap._name;
    this->intializeDefaultValue();
    std::cout << "SCAV-TP " << this->_name << " was born"
    << std::endl;
}

void ScavTrap::printStatus()
{
    if (this->_HP > 0)
        std::cout << "SCAV-TP " << this->_name << " feels great at "
        << this->_HP << " HP" << std::endl;
    else
        std::cout << "SCAV-TP " << this->_name << " feels bad at "
        << this->_HP << " HP" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    amount -= this->_armorDamageReduction;
    if (amount < 0)
        amount = 0;
    std::cout << "SCAV-TP " << this->_name << " filled pain and got "
    << amount << " damage" << std::endl;
    this->_HP -= amount;
    if (this->_HP < 0)
        this->_HP = 0;
    this->printStatus();
}

void ScavTrap::beRepaired(unsigned int amount)
{
    std::cout << "SCAV-TP " << this->_name <<
    " received new tasty food "
    << amount << " HP" << std::endl;
    this->_HP += amount;
    if (this->_HP > this->_MaxHP)
        this->_HP = this->_MaxHP;
    this->printStatus();
}