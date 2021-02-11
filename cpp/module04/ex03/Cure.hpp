#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        ~Cure();
        Cure(Cure const &cure);
        void operator=(Cure const &cure);
        void use(ICharacter &target);
        AMateria *clone() const;
};

#endif