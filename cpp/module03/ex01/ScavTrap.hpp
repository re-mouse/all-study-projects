#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <time.h>

class ScavTrap
{
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap &ScavTrap);
        ~ScavTrap();
        void operator=(ScavTrap &ScavTrap);
        void rangedAttack(std::string const &target);
        void meleeAttack(std::string const &target);
        void takeDamage(unsigned int amount);
        void printStatus();
        void challengeNewComer(std::string const & target);
        void beRepaired(unsigned int amount);
    private:
        void intializeDefaultValue();
        ScavTrap();
        int _HP;
        int _MaxHP;
        int _EP;
        int _MaxEP;
        int _lvl;
        int _meleeDamage;
        int _rangeDamage;
        int _armorDamageReduction;
        std::string _name;
};

#endif