#include "MateriaSource.hpp"

MateriaSource::MateriaSource() 
{
    for (int i = 0; i < inventoryCapacity; i++)
    {
        _inventory[i] = NULL;
    }
}

void MateriaSource::operator=(MateriaSource const &mat)
{
    for (int i = 0; i < inventoryCapacity; i++)
    {
        if (_inventory[i] != NULL)
            delete _inventory[i];
        _inventory[i] = mat._inventory[i];
    }
}

void MateriaSource::learnMateria(AMateria *mat)
{
    if (mat == NULL)
        return ;
    int i;
    for (i = 0; i < inventoryCapacity && this->_inventory[i] != NULL; i++);
    if (i < inventoryCapacity && this->_inventory[i] == NULL)
        this->_inventory[i] = mat;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i]->getType() == type)
            return _inventory[i]->clone();
    }
    return (NULL);
}

MateriaSource::MateriaSource(MateriaSource const &mat)
{
    *this = mat;
}

MateriaSource::~MateriaSource() {}