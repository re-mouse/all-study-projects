#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
    public:
        SuperMutant();
        SuperMutant(SuperMutant &superMutant);
        void operator=(SuperMutant &superMutant);
        ~SuperMutant();
        void takeDamage(int dmg);
};

#endif
