#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

struct Data
{ 
    std::string s1;
    int n; 
    std::string s2;
};

class Serializer
{
    private:
        struct RawData
        {
            char s1[8];
            int n;
            char s2[8];
        };
    public:
        Serializer();
        ~Serializer();
        Serializer(Serializer const &);
        Serializer &operator=(Serializer const &);
        void *serialize(void);
        Data *deserialize(void *raw);
};

#endif