#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        const int inventoryCapacity;
        AMateria *_inventory[4];
        Character();
    public:
        Character(std::string const &  name);
        ~Character();
        Character(Character &character);
        void operator=(Character &character);
        std::string const & getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif