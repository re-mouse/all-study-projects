#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
    public:
        void SetTypeAndName(std::string type, std::string name);
        void announce();
        ~Zombie();
        Zombie(std::string name, std::string type);
        Zombie();
    private:
        std::string _type;
        std::string _name;
};

#endif