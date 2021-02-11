#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
    std::cout << "Some random victim called " << this->_name << " just appeared!\n";
    std::cout << "Zog zog\n";
}

Peon::Peon(Peon  &peon) : Victim(peon._name)
{
    std::cout << "Some random victim called " << this->_name << " just appeared!\n";
    std::cout << "Zog zog\n";
}

Peon::~Peon()
{
    std::cout << "Bleuark...\n"; 
    std::cout << "Victim " << this->_name << " just died for no apparent reason!" << std::endl; 
}

void Peon::operator=(Peon &peon)
{
    (Victim)(*this) = peon;
}

std::string Peon::introducingString()
{
    return  ("I'm " + this->_name + "  and I like otters!\n");
}

void Peon::getPolymorphed() const
{
    std::cout << this->_name << " has been turned into a pink pony!\n";
}

void Peon::selfIntroducing()
{
    std::cout << this->introducingString();
}

std::ostream& operator<< (std::ostream& is, Peon &Peon)
{
    is << Peon.introducingString();
    return is;
}