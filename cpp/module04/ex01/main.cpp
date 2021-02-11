#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "Character.hpp"

int main()
{
    Character* me = new Character("me");
    std::cout << *me;
    Enemy* b = new RadScorpion();
    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();
    Enemy *s = new SuperMutant();
    me->equip(pr);
    std::cout << *me;
    me->equip(pf);
    me->attack(s);
    SuperMutant r;
    SuperMutant a(r);
    a.takeDamage(25);
    std::cout  << a.getHP() << std::endl;
    r = a;
    std::cout << r.getHP() << std::endl;
    Enemy g(*s);
    me->attack(b);
    std::cout << *me;
    me->equip(pr);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;
    me->attack(&g);
    std::cout << *me;
    std::cout << g.getHP() << std::endl;
    delete pf;
    delete pr;
    delete me;
    delete s;
}