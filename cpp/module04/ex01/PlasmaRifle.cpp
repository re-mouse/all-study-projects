#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::~PlasmaRifle() {}

PlasmaRifle::PlasmaRifle(PlasmaRifle &plasmaRifle) : AWeapon(plasmaRifle) {}

void PlasmaRifle::operator=(PlasmaRifle &plasmaRifle)
{
    AWeapon &temp = *this;
    temp = plasmaRifle;
}

void PlasmaRifle::attack() const
{
    std::cout <<  "* piouuu piouuu piouuu *\n";
}
