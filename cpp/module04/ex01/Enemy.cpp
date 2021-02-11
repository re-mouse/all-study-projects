#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type)
{
    this->_hp = hp;
    this->_type = type;
}

int Enemy::getHP() const
{
    return (this->_hp);
}

std::string Enemy::getType() const
{
    return (this->_type);
}

Enemy::Enemy() {}

void Enemy::operator=(Enemy &enemy)
{
    this->_type = enemy._type;
    this->_hp = enemy._hp;
}

Enemy::Enemy(Enemy &enemy)
{
    this->_type = enemy._type;
    this->_hp = enemy._hp;
}

void Enemy::takeDamage(int dmg)
{
    if (dmg >= 0)
    {
        this->_hp -= dmg;
        if (this->_hp < 0)
            this->_hp = 0;
    }
}

Enemy::~Enemy() {}