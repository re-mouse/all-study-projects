#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>

class Enemy
{
    protected:
        int _hp;
        std::string _type;
        Enemy(int hp, std::string const & type);
    private:
        Enemy();
    public:
        Enemy(Enemy &enemy);
        void operator=(Enemy &enemy);
        virtual ~Enemy();
        std::string getType() const;
        int getHP() const;
        virtual void takeDamage(int);
};

#endif