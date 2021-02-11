#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP


#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap &fragTrap);
        ~FragTrap();
        void operator=(FragTrap &fragTrap);
        void rangedAttack(std::string const &target);
        void meleeAttack(std::string const &target);
        void vaulthunter_dot_exe(std::string const & target);
    private:
        void intializeDefaultValue();
        FragTrap();
};

#endif