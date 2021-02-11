#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>

class Pony
{
    public:
        Pony(std::string name);
        ~Pony();
    private:
        std::string name;
        Pony();
};

#endif