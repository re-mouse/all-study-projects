#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
    public:
        RadScorpion();
        RadScorpion(RadScorpion &RadScorpion);
        void operator=(RadScorpion &RadScorpion);
        ~RadScorpion();
};

#endif
