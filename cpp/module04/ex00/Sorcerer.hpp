#ifndef SORCERER_HPP
#define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"

class Sorcerer
{
    public:
        Sorcerer(std::string name, std::string title);
        ~Sorcerer();
        void selfIntroducing();
        Sorcerer(Sorcerer &sorcerer);
        std::string introducingString();
        void operator =(Sorcerer &Sorcerer);
        void polymorph(Victim const &);
    private:
        std::string _name;
        std::string _title;
        Sorcerer();
};

std::ostream& operator<< (std::ostream& is, Sorcerer &sorcerer);

#endif