#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <unistd.h>

Base * generate(void)
{
    std::srand( (unsigned) time(NULL) * getpid());
    int i = std::rand() % 3;
    if (i == 0)
    {
        std::cout << "Created A\n";
        return new A;
    }
    else if (i == 1)
    {
        std::cout << "Created B\n";
        return new B;
    }
    else
    {
        std::cout << "Created C\n";
        return new C;
    }
}

void identify_from_pointer(Base * p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "It's A pointer\n";
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "It's B pointer\n";
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "It's C pointer\n";
    else
        std::cout << "Unknown type\n";
}

void identify_from_reference(Base &p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "It's A ref\n";
        return ;
    }
    catch (std::bad_cast &ex) {}
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "It's B ref\n";
        return ;
    }
    catch (std::bad_cast &ex) {}
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "It's C ref\n";
        return ;
    }
    catch (std::bad_cast &ex) {}
}

int main()
{
    Base *temp = generate();
    identify_from_pointer(temp);
    Base &ref = *temp;
    identify_from_reference(ref);
}