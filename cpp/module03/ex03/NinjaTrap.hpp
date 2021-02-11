#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
    public:
        NinjaTrap(std::string name);
        NinjaTrap(NinjaTrap &ninjaTrap);
        ~NinjaTrap();
        void operator=(NinjaTrap &ninjaTrap);
        void rangedAttack(std::string const &target);
        void meleeAttack(std::string const &target);
        void ninjaShoebox(FragTrap  & target);
        void ninjaShoebox(ScavTrap  & target);
        void ninjaShoebox(ClapTrap  & target);
        void ninjaShoebox(NinjaTrap  & target);
    private:
        void intializeDefaultValue();
        NinjaTrap();
};

#endif