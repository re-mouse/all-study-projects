#include "ZombieEvent.hpp"

void zombieOnStack()
{
    Zombie zombie("MARSEL", "Novice");
    zombie.announce();
}

void randomChump()
{
    std::srand(time(0));
    std::string names[] = {"DIMON", "TIMOFEY", "SANYA"};
    ZombieEvent zombievent("Fast");
    Zombie *zombie = zombievent.newZombie(names[std::rand() % 3]);
    zombie->announce();
    delete(zombie);
    zombievent.setZombieType("Smart");
    Zombie *zombieS = zombievent.newZombie(names[(5 * std::rand()) % 3]);
    zombieS->announce();
    delete(zombieS);
}

int main()
{
    zombieOnStack();
    randomChump();
}