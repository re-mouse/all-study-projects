#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "ISquad.hpp"
#include <iostream>

class Squad : public ISquad
{
    private:
        ISpaceMarine **spaceMarines;
    public:
        ~Squad();
        Squad();
        Squad(Squad &squad);
        void operator=(Squad &squad);
        int getCount() const;
        ISpaceMarine *getUnit(int) const;
        int push(ISpaceMarine *);
};

#endif