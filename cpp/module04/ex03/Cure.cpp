#include "Cure.hpp"

void Cure::use(ICharacter &target)
{
    AMateria::use(target);
    std::cout << "* heals " << target.getName() << "'s wounds" << std::endl;
}

Cure::~Cure(){}

Cure::Cure() : AMateria("cure") 
{
    
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

Cure::Cure(Cure const &cure) : AMateria("cure")
{
    *this = cure;
}

void Cure::operator=(Cure const &cure)
{
    this->_xp = cure._xp;
}