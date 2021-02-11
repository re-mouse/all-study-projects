#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}

void Fixed::operator = (const Fixed &A)
{
    std::cout << "Assignation operator called" << std::endl;
    this->fixedPointValue =  A.getRawBits();
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPointValue);
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}