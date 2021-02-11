#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
{
    this->_name = name;
    this->_title = title;
    std::cout << this->_name << " " << this->_title << " is born" << std::endl; 
}

void Sorcerer::polymorph(Victim const &victim)
{
    victim.getPolymorphed();
}


Sorcerer::Sorcerer(Sorcerer &sorc)
{
    this->_name = sorc._name;
    this->_title = sorc._title;
}

void Sorcerer::operator=(Sorcerer &sorcerer)
{
    this->_name = sorcerer._name;
    this->_title = sorcerer._title;
}

Sorcerer::~Sorcerer()
{
    std::cout << this->_name << " " << this->_title << " is dead. Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::introducingString()
{
    return  ("I am " + this->_name + " " + this->_title + " and I like ponies!\n");
}
void Sorcerer::selfIntroducing()
{
    std::cout << this->introducingString();
}

std::ostream& operator<< (std::ostream& is, Sorcerer &sorcerer)
{
    is << sorcerer.introducingString();
    return is;
}