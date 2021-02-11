#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <time.h>

class FragTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap &fragTrap);
        ~FragTrap();
        void operator=(FragTrap &fragTrap);
        void rangedAttack(std::string const &target);
        void meleeAttack(std::string const &target);
        void takeDamage(unsigned int amount);
        void printStatus();
        void vaulthunter_dot_exe(std::string const & target);
        void beRepaired(unsigned int amount);
    private:
        void intializeDefaultValue();
        FragTrap();
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