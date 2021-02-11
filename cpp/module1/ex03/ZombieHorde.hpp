#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
    public:
        ZombieHorde(int N, std::string type);
        Zombie *zombies;
        void announce();
        ~ZombieHorde();
        
    private:
        int zombieQuantity;
        ZombieHorde();
    
};

#endif