#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <time.h>

class ClapTrap
{
    public:
        ClapTrap(std::string name);
        ClapTrap(ClapTrap &ClapTrap);
        ~ClapTrap();
        void operator=(ClapTrap &ClapTrap);
        void rangedAttack(std::string const &target);
        void meleeAttack(std::string const &target);
        void takeDamage(unsigned int amount);
        std::string getName(void);
        void printStatus();
        void beRepaired(unsigned int amount);
        ClapTrap();
    private:
        void intializeDefaultValue();
    protected:
        int _HP;
        int _MaxHP;
        int _EP;
        int _MaxEP;
        int _lvl;
        int _meleeDamage;
        int _rangeDamage;
        int _armorDamageReduction;
        std::string _type;
        std::string _name;
};

#endif