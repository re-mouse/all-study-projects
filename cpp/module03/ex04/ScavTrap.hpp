#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap &scavTrap);
        ~ScavTrap();
        void operator=(ScavTrap &scavTrap);
        void challengeNewComer(std::string const &target);
        void rangedAttack(std::string const &target);
        void meleeAttack(std::string const &target);
        void trapAttack(ScavTrap &scavTrap);
    private:
        void intializeDefaultValue();
        ScavTrap();
};

#endif