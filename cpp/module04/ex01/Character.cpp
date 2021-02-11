#include "Character.hpp"

Character::Character(std::string const &name)
{
    this->_name = name;
    this->_curWeapon = NULL;
    this->_ap = 40;
}

Character::Character(Character &character)
{
    this->_name = character._name;
}

void Character::equip(AWeapon *aweapon)
{
    this->_curWeapon = aweapon;
}

std::string Character::getName() const
{
    return (this->_name);
}

int Character::getAP() const
{
    return (this->_ap);
}

AWeapon* Character::getWeapon() const
{
    return (this->_curWeapon);
}

std::ostream &operator<<(std::ostream &os, const Character &character)
{
    if (character.getWeapon() != NULL)
        os << character.getName() << " has " << character.getAP() << " AP and wields a " \
        << character.getWeapon()->getName() << std::endl;
    else
        os << character.getName() << " has " << character.getAP() << " AP and is unarmed\n";
    return (os);
}

Character::~Character() {
    std::cout << "lol.." << std::endl;
}

void Character::attack(Enemy *enemy)
{
    if (this->getWeapon() == NULL)
        return ;
    if (this->_ap - this->getWeapon()->getAPCost() > 0)
    {
        std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->getWeapon()->getName() << std::endl;
        enemy->takeDamage(this->getWeapon()->getDamage());
        this->getWeapon()->attack();
        if (enemy->getHP() <= 0)
            delete enemy;
        this->_ap -= this->getWeapon()->getAPCost();
    }
}

void Character::operator=(Character &character)
{
    this->_ap = character._ap;
    this->_curWeapon = character._curWeapon;
    this->_name = character._name;
}

void Character::recoverAP()
{
    this->_ap += 10;
    if(this->_ap > 40)
        this->_ap = 40;
}