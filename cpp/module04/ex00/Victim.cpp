#include "Victim.hpp"

Victim::Victim(std::string name)
{
    this->_name = name;
    std::cout << "Some random victim called " << this->_name << " just appeared!" << std::endl;
}

Victim::Victim(Victim &vict)
{
    this->_name = vict._name;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->_name << " just died for no apparent reason!" << std::endl; 
}

void Victim::operator=(Victim &victim)
{
    this->_name = victim._name;
}

std::string Victim::introducingString()
{
    return  ("I'm " + this->_name + "  and I like otters!\n");
}

void Victim::getPolymorphed() const
{
    std::cout << this->_name << " has been turned into a cute little sheep!\n";
}

void Victim::selfIntroducing()
{
    std::cout << this->introducingString();
}

std::ostream& operator<< (std::ostream& is, Victim &victim)
{
    is << victim.introducingString();
    return is;
}