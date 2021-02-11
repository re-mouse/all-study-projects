#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &obj);
        void operator = (const Fixed &A);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
};

#endif