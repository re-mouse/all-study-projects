#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
    public:
        void attack() const;
        PowerFist(void);
        PowerFist(PowerFist &powerFist);
        ~PowerFist();
        void operator=(PowerFist &powerFist);
};

#endif