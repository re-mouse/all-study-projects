#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *pointer = &str;
    std::string &ref = *pointer;
    std::cout << *pointer << "\n" << ref << "\n";
}