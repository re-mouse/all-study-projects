#include "ZombieHorde.hpp"

void ZombieHorde::announce()
{
    int i = 0;
    while (i < this->zombieQuantity)
        this->zombies[i++].announce();
}

ZombieHorde::ZombieHorde(int N, std::string type)
{
    std::srand(time(0));
    this->zombieQuantity = N;
    this->zombies = new Zombie[N];
    std::string namePool[] = {"Stepa", "Grisha", "Karim", "Anton"};
    int i = 0;
    while (i < N)
    {
        this->zombies[i++].SetTypeAndName(type, namePool[std::rand() % 4]);
    }
}

ZombieHorde::~ZombieHorde()
{
    delete [] this->zombies;
}