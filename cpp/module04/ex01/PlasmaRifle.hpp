#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
    public:
        void attack() const;
        PlasmaRifle(void);
        PlasmaRifle(PlasmaRifle &plasmaRifle);
        ~PlasmaRifle();
        void operator=(PlasmaRifle &plasmaRifle);
};

#endif