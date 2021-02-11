#ifndef CASTER_HPP
#define CASTER_HPP

#include <iostream>
#include <cmath>


class Caster
{
    private:
        enum type{_float, _int, _double, _char, _error, _nan, _posinf, _neginf};
        Caster();
        type isFloatOrInt(std::string stringToParse);
        type parseString(std::string stringToParse);
        struct ValueContainer
        {
            char charValue;
            int intValue;
            float floatValue;
            double doubleValue;
            Caster::type originalType;
        };
        ValueContainer currentValue;
        void makeDoubleConvert(ValueContainer &, std::string);
        void makeFloatConvert(ValueContainer &, std::string);
        void makeIntConvert(ValueContainer &, std::string);
        void makeCharConvert(ValueContainer &, std::string);
        const std::string originalString;
    public:
        Caster(const std::string toCast);
        Caster(Caster const &);
        std::string getCharString();
        std::string getIntString();
        std::string getFloatString();
        std::string getDoubleString();
        ~Caster();
        Caster &operator=(const Caster &);
};

#endif