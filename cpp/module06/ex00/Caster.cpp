#include "Caster.hpp"
#include <exception>
#include <math.h>

Caster::Caster(const std::string toCast) : originalString(toCast) 
{
    currentValue.originalType = parseString(originalString);
    if (currentValue.originalType == _double)
        makeDoubleConvert(currentValue, originalString);
    else if (currentValue.originalType == _float)
        makeFloatConvert(currentValue, originalString);
    else if (currentValue.originalType == _int)
        makeIntConvert(currentValue, originalString);
    else if (currentValue.originalType == _char)
        makeCharConvert(currentValue, originalString);
}

void Caster::makeCharConvert(Caster::ValueContainer &val, std::string value)
{
    try
    {
        val.charValue = value[0];
        val.doubleValue = static_cast<double>(val.charValue);
        val.floatValue = static_cast<float>(val.charValue);
        val.intValue = static_cast<int>(val.charValue);
    }
    catch (std::exception &ex)
    {
        val.originalType = _error;
    }
}

void Caster::makeDoubleConvert(Caster::ValueContainer &val, std::string value)
{
    try
    {
        val.doubleValue = std::stod(value);
        val.floatValue = static_cast<float>(val.doubleValue);
        val.intValue = static_cast<int>(val.doubleValue);
        val.charValue = static_cast<char>(val.doubleValue);
    }
    catch (std::exception &ex)
    {
        val.originalType = _error;
    }
}

void Caster::makeFloatConvert(Caster::ValueContainer &val, std::string value)
{
    try
    {
        val.floatValue = std::stof(value);
        val.doubleValue = static_cast<double>(val.floatValue);
        val.intValue = static_cast<int>(val.floatValue);
        val.charValue = static_cast<char>(val.floatValue);
    }
    catch (std::exception &ex)
    {
        val.originalType = _error;
    }
}

void Caster::makeIntConvert(Caster::ValueContainer &val, std::string value)
{
    try
    {
        val.intValue = std::stoi(value);
        val.floatValue = static_cast<float>(val.intValue);
        val.doubleValue = static_cast<double>(val.intValue);
        val.charValue = static_cast<char>(val.intValue);
    }
    catch (std::exception &ex)
    {
        val.originalType = _error;
    }
}

Caster::type Caster::isFloatOrInt(std::string stringToParse)
{
    int dotFlag = 0;
    if(stringToParse[0] == '-' || stringToParse[0] == '+')
        stringToParse = stringToParse.erase(0, 1);
    for (unsigned long long i = 0; i < stringToParse.length(); i++)
    {
        if (!std::isdigit(stringToParse[i]))
        {
            if (stringToParse[i] == '.' && dotFlag == 0)
            {
                if (std::isdigit(stringToParse[i + 1]))
                    dotFlag = 1;
                else
                    return _error;
            }
            else
                return _error;
        }
    }
    if (dotFlag == 1)
        return _double;
    else
        return _int;
}

Caster::type Caster::parseString(std::string stringToParse)
{
    try
    {
        if (stringToParse == "nan" || stringToParse == "nanf")
            return _nan;
        if (stringToParse == "-inff" || stringToParse == "-inf")
            return _neginf;
        if (stringToParse == "+inff" || stringToParse == "+inf")
            return _posinf;
        if(stringToParse[0] == '-' || stringToParse[0] == '+')
            stringToParse = stringToParse.erase(0, 1);
        if (std::isdigit(stringToParse[0]))
        {
            if (stringToParse[stringToParse.length() - 1] == 'f')
            {
                std::string stringToParseType = stringToParse;
                stringToParseType.pop_back();
                if (isFloatOrInt(stringToParseType) == _double)
                    return _float;
                else
                    return _error;
            }
            else
                return isFloatOrInt(stringToParse);
        }
        else if (originalString.length() == 1 && stringToParse[0] >= 32 && stringToParse[0] <= 126)
            return _char;
        else
            return _error;
    }
    catch (std::exception &ex)
    {
        return _error;
    }
}

Caster::~Caster() {}

Caster::Caster(Caster const &copy) : originalString(copy.originalString) 
{
    this->currentValue = copy.currentValue;
}

Caster &Caster::operator=(Caster const &cast) 
{
    this->currentValue = cast.currentValue;
    return *this;
}

std::string Caster::getCharString()
{
    if (currentValue.originalType == _error || currentValue.originalType == _posinf 
    || currentValue.originalType == _neginf || currentValue.originalType == _nan) 
        return "impossible";
    if (currentValue.originalType != _char && currentValue.doubleValue > 127)
        return "impossible";
    if (currentValue.charValue >= 32 && currentValue.charValue <= 126)
    {
        std::string charString = "'_'";
        charString[1] = currentValue.charValue;
        return charString;
    }
    else
        return "Non displayable";
}

std::string Caster::getDoubleString()
{
    if (currentValue.originalType == _error)
        return "impossible";
    if (currentValue.originalType == _nan)
        return "nan";
    else if (currentValue.originalType == _neginf)
        return "-inf";
    else if (currentValue.originalType == _posinf)
        return "+inf";
    std::string doubleString = std::to_string(currentValue.doubleValue);
    while (doubleString[doubleString.length() - 1] == '0')
        doubleString.pop_back();
    if (std::fmod(currentValue.doubleValue, 1) != 0)
        return doubleString;
    else
        doubleString += "0";
    return doubleString;
}

std::string Caster::getIntString()
{
    if (currentValue.originalType == _error || currentValue.originalType == _posinf 
    || currentValue.originalType == _neginf || currentValue.originalType == _nan) 
        return "impossible";
    if (currentValue.originalType != _char && currentValue.originalType != _int)
        if (currentValue.doubleValue < INT_MIN || currentValue.doubleValue > INT_MAX)
            return "impossible";
    std::string intString = std::to_string(currentValue.intValue);
    return intString;
}

std::string Caster::getFloatString()
{
    if (currentValue.originalType == _error)
        return "impossible";
    if (currentValue.originalType == _nan)
        return "nanf";
    else if (currentValue.originalType == _neginf)
        return "-inff";
    else if (currentValue.originalType == _posinf || currentValue.floatValue == std::numeric_limits<float>::infinity())
        return "+inff";
    std::string floatString = std::to_string(currentValue.floatValue);
    while (floatString[floatString.length() - 1] == '0')
        floatString.pop_back();
    if (std::fmod(currentValue.floatValue, 1) != 0)
        floatString += "f";
    else
        floatString += "0f";
    return floatString;
}