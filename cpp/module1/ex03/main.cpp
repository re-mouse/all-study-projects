#include "ZombieHorde.hpp"

void hordeTest()
{
    ZombieHorde horde(5, "Slave");
    horde.announce();

}

int main()
{
    hordeTest();

    ZombieHorde horde(2, "Master");
    horde.announce();
}