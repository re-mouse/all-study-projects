#include "Sorcerer.hpp"

void defaultTest()
{
    Sorcerer robert("Robert", "the Magnificent");
    Victim jim("Jimmy");
    Peon joe("Joe");
    std::cout << robert << jim << joe;
    robert.polymorph(jim);
    robert.polymorph(joe);
}

int main()
{
    defaultTest(); 
    std::cout << "\n\nNEXTTEST\n";
    Sorcerer testirovshik("Mike", "Tester");
    Sorcerer teammate("Mikle", "Victim Tester");
    Peon who("Margon");
    testirovshik = teammate;
    testirovshik.selfIntroducing();
    testirovshik.polymorph(who);
}