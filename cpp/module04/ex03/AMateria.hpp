#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    private:
        AMateria();
    protected:
        std::string _type;
        unsigned int _xp;
    public:
        AMateria(std::string const & type);
        AMateria(AMateria &amateria);
        virtual ~AMateria();
        void operator= (AMateria &amateria);
        std::string const & getType() const;
        unsigned int getXP() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif