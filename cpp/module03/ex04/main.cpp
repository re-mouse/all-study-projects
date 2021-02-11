#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "SuperTrap.hpp"

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


    std::cout << "\n\nSCAVTRAP TEST\n\n";
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



    std::cout << "\n\nNINJATRAP TEST\n\n";
    NinjaTrap ninja("Jack");
    ninja.ninjaShoebox(rosha);
    ninja.ninjaShoebox(misha);
    NinjaTrap sonofninja(ninja);
    ninja = sonofninja;
    ninja.takeDamage(30);
    ninja.meleeAttack("STUL");
    ninja.rangedAttack("TABURETKA");
    ninja.ninjaShoebox(b);

    std::cout << "\n\nCLAPTRAP TEST\n\n";
    ClapTrap yaustaluje("eto ochen skuchno");
    yaustaluje.meleeAttack("hvatit");
    ClapTrap yaPravdaUstalPridumivatEtiNazvania("CHESTNO");
    yaPravdaUstalPridumivatEtiNazvania = yaustaluje;
    yaPravdaUstalPridumivatEtiNazvania.meleeAttack("YA NE ZNAY UJE IMEN");
    yaPravdaUstalPridumivatEtiNazvania.takeDamage(123);

    std::cout << "\n\nSUPERTRAPTEST\n\n\n";
    SuperTrap muravei("muravei");
    muravei.ninjaShoebox(ninja);
    muravei.meleeAttack("TESTDUMMY");
    muravei.rangedAttack("random guy");
    muravei.ninjaShoebox(gosha);
    muravei.vaulthunter_dot_exe("himself");
    muravei.takeDamage(50);
}