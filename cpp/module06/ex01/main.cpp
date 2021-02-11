#include "Serializer.hpp"

int main()
{
    Serializer ser;
    void *rawData = ser.serialize();
    Data *dataTest = ser.deserialize(rawData);
    std::cout << dataTest->s1 << std::endl;
    std::cout << dataTest->n << std::endl;
    std::cout << dataTest->s2 << std::endl;
}