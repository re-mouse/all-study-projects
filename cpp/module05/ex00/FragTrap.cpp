#include "FragTrap.hpp"

void FragTrap::intializeDefaultValue()
{
    this->_HP = 100;
    this->_MaxHP = 100;
    this->_EP = 100;
    this->_MaxEP = 100;
    this->_lvl = 1;
    this->_meleeDamage = 30;
    this->_rangeDamage = 20;
    this->_armorDamageReduction = 5;
}

FragTrap::FragTrap(std::string name)
{
    this->_name = name;
    this->intializeDefaultValue();
    std::cout << "FR4G-TP " << this->_name << " was delivered from the factory"
    << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
    std::srand(time(NULL));
    std::string attacks[] = {" by throwing gears", " by burning with a laser", " by hacking implant",
    " by creating a spelling heart attack", " by stroking"};
    int attackId = std::rand() % 5;
    if (this->_EP - 25 >= 0)
    {
        std::cout << "FR4G-TP " << this->_name << " attacks "
        << target << attacks[attackId] << ", causing " << this->_rangeDamage
        << " points of damage!" << std::endl;
        this->_EP -= 25;
        if (this->_EP < 0)
            this->_EP = 0;
    }
    else
    {
        std::cout << "FR4G-TP " << this->_name << " is out of energy, to make attack" << std::endl;
    }
}

FragTrap::~FragTrap()
{
    std::cout << "FR4G-TP " << this->_name << " was disassembled into gears"
    << std::endl;
}

void FragTrap::rangedAttack(std::string const &target)
{
    std::cout << "FR4G-TP " << this->_name << " attacks "
    << target << " at range, causing " << this->_rangeDamage
    << " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target)
{
    std::cout << "FR4G-TP " << this->_name << " attacks "
    << target << " at melee, causing " << this->_meleeDamage
    << " points of damage!" << std::endl;
}

void FragTrap::operator=(FragTrap &fragTrap)
{
    this->_name = fragTrap._name;
    std::cout << "Some FR4G-TP got " << this->_name << " name" << std::endl;
}

FragTrap::FragTrap(FragTrap &fragTrap)
{
    this->_name = fragTrap._name;
    this->intializeDefaultValue();
    std::cout << "FR4G-TP " << this->_name << " was delivered from the factory"
    << std::endl;
}

void FragTrap::printStatus()
{
    if (this->_HP > 0)
        std::cout << "FR4G-TP " << this->_name << " feels good at "
        << this->_HP << " HP" << std::endl;
    else
        std::cout << "FR4G-TP " << this->_name << " doesn't feel anything at "
        << this->_HP << " HP" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    amount -= this->_armorDamageReduction;
    if (amount < 0)
        amount = 0;
    std::cout << "FR4G-TP " << this->_name << " filled pain and got "
    << amount << " damage" << std::endl;
    this->_HP -= amount;
    if (this->_HP < 0)
        this->_HP = 0;
    this->printStatus();
}

void FragTrap::beRepaired(unsigned int amount)
{
    std::cout << "FR4G-TP " << this->_name <<
    " received new parts and got "
    << amount << " HP" << std::endl;
    this->_HP += amount;
    if (this->_HP > this->_MaxHP)
        this->_HP = this->_MaxHP;
    this->printStatus();
}