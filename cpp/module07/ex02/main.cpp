#include "Array.hpp"
#include <iostream>
#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>

int main()
{
    Array<int, 8>a(8);
    a[0] = 15;
    try
    {
        a[6] = 0;
        std::cout << "a[6] assignation been okay\n";
    }
    catch (std::exception)
    {
        std::cout << "a[6] invoked exception\n";
    }
    try
    {
        a[-1] = 0;
        std::cout << "a[-1] assignation been okay\n";
    }
    catch (std::exception)
    {
        std::cout << "a[-1] invoked exception\n";
    }
    a[2] = 10;
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << std::endl;
    std::cout << "random values from heap\n";
	Array<int, 14>b;
    b[5] = 10;
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << std::endl;
}
