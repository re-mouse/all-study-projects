#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!\n";
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh...\n";
}

void SuperMutant::takeDamage(int dmg)
{
    dmg -= 3;
    if (dmg >= 0)
    {
        this->_hp -= dmg;
        if (this->_hp < 0)
            this->_hp = 0;
    }
}

SuperMutant::SuperMutant(SuperMutant &superMutant) : Enemy(superMutant) 
{
    std::cout << "Gaaah. Me want smash heads!\n";
}

void SuperMutant::operator=(SuperMutant &superMutant)
{
    Enemy &temp = *this;
    temp = superMutant;
}