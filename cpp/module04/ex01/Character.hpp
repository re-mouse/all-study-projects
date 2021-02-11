#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
    private:
        std::string _name;
        AWeapon *_curWeapon;
        Character();
        int _ap;
    public:
        ~Character();
        Character(Character &character);
        int getAP() const;
        AWeapon* getWeapon() const;
        Character(std::string const & name);
        void operator=(Character &character);
        void recoverAP();
        void equip(AWeapon*);
        void attack(Enemy*);
        std::string getName() const;
};

std::ostream& operator<<(std::ostream &os, const Character &character);

#endif