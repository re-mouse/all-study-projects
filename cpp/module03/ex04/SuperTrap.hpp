#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
    public:
        SuperTrap(std::string name);
        SuperTrap(SuperTrap &SuperTrap);
        ~SuperTrap();
        void operator=(SuperTrap &SuperTrap);
        void challengeNewComer(std::string const & target);
        void rangedAttack(std::string const &target);
        void meleeAttack(std::string const &target);
        void trapAttack(SuperTrap &SuperTrap);
    private:
        void intializeDefaultValue();
        SuperTrap();
};

#endif