#include "iter.hpp"
#include <iostream>
#include <string>

template<typename T>
void print(T &printObject)
{
    std::cout << printObject << std::endl;
}

void incrementValue(int &v)
{
    v++;
}

int main()
{
    int a[] = {12, 53, 5412, 5412};
    std::string test[] = {"ITS TEST1", "ITS TEST2", "HI", "NICE D.. BRO"};
    iter(a, sizeof(a) / sizeof(int), print);
    iter(a, sizeof(a) / sizeof(int), incrementValue);
    std::cout << "VALUES AFTER INCREMENT\n";
    iter(a, sizeof(a) / sizeof(int), print);
    iter(test, sizeof(test) / sizeof(std::string), print);
}