#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *\n";
}

RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *\n";
}

RadScorpion::RadScorpion(RadScorpion &RadScorpion) : Enemy(RadScorpion) 
{
    std::cout << "* click click click *\n";
}

void RadScorpion::operator=(RadScorpion &RadScorpion)
{
    Enemy &temp = *this;
    temp = RadScorpion;
}