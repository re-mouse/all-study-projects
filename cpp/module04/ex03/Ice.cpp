#include "Ice.hpp"

void Ice::use(ICharacter &target)
{
    AMateria::use(target);
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

Ice::~Ice()
{
    
}

Ice::Ice() : AMateria("ice") {}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

Ice::Ice(Ice const &ice) : AMateria("ice")
{
    *this = ice;
}

void Ice::operator=(Ice const &ice)
{
    this->_xp = ice._xp;
}