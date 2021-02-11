#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
    this->_type = type;
}

void AMateria::use(ICharacter &)
{
    _xp += 10;
}

void AMateria::operator=(AMateria &amateria)
{
    this->_xp = amateria._xp;
}

AMateria::~AMateria() {}

AMateria::AMateria(AMateria &amateria)
{
    this->_xp = amateria._xp;
}

unsigned int AMateria::getXP() const
{
    return (this->_xp);
}

std::string const & AMateria::getType() const
{
    return this->_type;
}