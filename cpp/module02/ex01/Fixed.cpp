#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int intNum)
{
    this->fixedPointValue = intNum * (1 << this->fractionalBits);
    std::cout << "Int constructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
    os << fix.toFloat();
    return os;
}

Fixed::Fixed(float floatNum)
{
    this->fixedPointValue = (roundf(floatNum * (1 << this->fractionalBits)));
    std::cout << "Float constructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

void Fixed::operator = (const Fixed &A)
{
    std::cout << "Assignation operator called" << std::endl;
    this->fixedPointValue =  A.getRawBits();
}

int Fixed::getRawBits(void) const
{
    return (this->fixedPointValue);
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

int Fixed::toInt() const
{
    return (this->fixedPointValue / (1 << this->fractionalBits));
}

float Fixed::toFloat() const
{
     return (1.0 * this->fixedPointValue / (1 << this->fractionalBits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}