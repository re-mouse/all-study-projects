#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
    this->_name = name;
    this->_apCost = apcost;
    this->_damage = damage;
}

std::string AWeapon::getName() const
{
    return (this->_name);
}

int AWeapon::getAPCost() const
{
    return (this->_apCost);
}

int AWeapon::getDamage() const
{
    return (this->_damage);
}

AWeapon::AWeapon() {}

void AWeapon::operator=(AWeapon &aweapon)
{
    this->_name = aweapon._name;
    this->_damage = aweapon._damage;
    this->_apCost = aweapon._apCost;
}

AWeapon::AWeapon(AWeapon &aweapon)
{
    this->_name = aweapon._name;
    this->_damage = aweapon._damage;
    this->_apCost = aweapon._apCost;
}

AWeapon::~AWeapon() {}