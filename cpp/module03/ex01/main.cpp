#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    FragTrap gosha("Gosha");
    gosha.meleeAttack("Elain");
    gosha.rangedAttack("Teburu");
    gosha.takeDamage(50);
    gosha.takeDamage(15);
    gosha.beRepaired(30);
    gosha.takeDamage(200);
    gosha.beRepaired(300);
    gosha.vaulthunter_dot_exe("Kolya");
    FragTrap b(gosha);
    FragTrap c("Grisha");
    b = c;
    b.takeDamage(10);
    c.takeDamage(15);
    std::cout << "\nSCAVTRAP TEST\n\n";
    ScavTrap misha("Mihail");
    misha.meleeAttack("Rojer");
    misha.rangedAttack("Makisa");
    misha.takeDamage(50);
    misha.takeDamage(15);
    misha.beRepaired(30);
    misha.takeDamage(200);
    misha.beRepaired(300);
    misha.challengeNewComer("Kolya");
    ScavTrap rosha("Roshan");
    ScavTrap creep("Creep");
    rosha = creep;
    rosha.takeDamage(10);
    creep.takeDamage(15);
}