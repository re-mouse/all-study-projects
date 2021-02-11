#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        static const int inventoryCapacity = 4;
        AMateria *_inventory[4];
    public:
        void learnMateria(AMateria *);
        AMateria *createMateria(std::string const & type);
        ~MateriaSource();
        MateriaSource();
        MateriaSource(MateriaSource const &materiaSource);
        void operator=(MateriaSource const &materiasource);
};

#endif