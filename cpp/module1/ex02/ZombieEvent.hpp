#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include "Zombie.hpp"

class ZombieEvent
{
    public:
        ZombieEvent(std::string type);
        void    setZombieType(std::string type);
        Zombie* newZombie(std::string name);
    private:
        ZombieEvent();
        std::string _type;
};

#endif