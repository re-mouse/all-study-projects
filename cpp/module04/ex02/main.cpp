#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"

int main()
{
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;
    Squad *test = new Squad();
    ISquad* vlc = test;
    vlc->push(bob);
    for (int i = 0; i < 10000; i++)
    {
        vlc->push(bob->clone());
        vlc->push(jim);
    }
    Squad test2;
    Squad *test3 = new Squad();
    *test3 = *test;
    test->push(jim);
    for (int i = 0; i < test3->getCount(); ++i)
    {
        ISpaceMarine* cur = test3->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
}