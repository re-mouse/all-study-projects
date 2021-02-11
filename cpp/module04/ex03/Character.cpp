#include "Character.hpp"

Character::Character(std::string const & name) : inventoryCapacity(4)
{
    this->_name = name;
    for (int i = 0; i < inventoryCapacity; i++)
        this->_inventory[i] = NULL;
}

Character::Character() : inventoryCapacity(4){}

std::string const &Character::getName() const 
{ 
    return this->_name; 
}

Character::~Character()
{
    for (int i = 0; i < inventoryCapacity; i++)
    {
        if (_inventory[i] != NULL)
            delete _inventory[i];
    }
}

void Character::operator=(Character &character)
{
    this->_name = character.getName();
    for (int i = 0; i < inventoryCapacity; i++)
    {
        if (character._inventory[i] != NULL)
            delete character._inventory[i];
        this->_inventory[i] = character._inventory[i];
    }
}

Character::Character(Character &character)  : inventoryCapacity(4)
{
    *this = character;
}

void Character::unequip(int idx)
{
    if (idx < inventoryCapacity && idx > 0)
        this->_inventory[idx] = NULL;
}

void Character::equip(AMateria *m)
{
    int i;
    if (m == NULL)
        return ;
    for (i = 0; i < inventoryCapacity && this->_inventory[i] != NULL; i++);
    if (i < inventoryCapacity && this->_inventory[i] == NULL)
        this->_inventory[i] = m;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < inventoryCapacity  && idx >= 0 && this->_inventory[idx] != NULL)
        this->_inventory[idx]->use(target);
}