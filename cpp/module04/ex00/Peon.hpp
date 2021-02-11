#ifndef PEON_HPP
#define PEON_HPP

#include <iostream>
#include "Victim.hpp"

class Peon : public Victim
{
    public:
        Peon(std::string name);
        Peon(Peon &);
        ~Peon();
        void selfIntroducing();
        std::string introducingString();
        void getPolymorphed() const;
        void operator =(Peon &Peon);
    private:
        Peon();
};

std::ostream& operator<< (std::ostream& is, Peon &Peon);

#endif