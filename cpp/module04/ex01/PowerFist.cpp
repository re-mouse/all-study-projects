#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50) {}

PowerFist::~PowerFist() {}

PowerFist::PowerFist(PowerFist &powerFist) : AWeapon(powerFist) {}

void PowerFist::operator=(PowerFist &powerFist)
{
    AWeapon &temp = *this;
    temp = powerFist;
}

void PowerFist::attack() const
{
    std::cout <<  "* pschhh... SBAM! *\n";
}
