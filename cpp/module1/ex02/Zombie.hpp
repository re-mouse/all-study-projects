#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
    public:
        void announce();
        ~Zombie();
        Zombie(std::string name, std::string type);
    private:
        Zombie();
        std::string _type;
        std::string _name;
};

#endif