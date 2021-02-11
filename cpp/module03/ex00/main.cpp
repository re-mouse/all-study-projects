#include "FragTrap.hpp"

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
}