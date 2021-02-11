#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
    public:
        Fixed();
        Fixed(int);
        Fixed(float);
        ~Fixed();
        Fixed(const Fixed &obj);
        void operator = (const Fixed &);
        int getRawBits( void ) const;
        void setRawBits( int const raw);
        float toFloat(void) const;
        int toInt(void) const;
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);

#endif