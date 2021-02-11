#include "ZombieEvent.hpp"

Zombie* ZombieEvent::newZombie(std::string name)
{
    return (new Zombie(name, this->_type));
}

void    ZombieEvent::setZombieType(std::string type)
{
    this->_type = type;
}

ZombieEvent::ZombieEvent(std::string type)
{
    this->_type = type;
}