#include "Pony.hpp"

void ponyOnTheHeap()
{
    Pony *pony = new Pony("Twilight sparkle");
    delete (pony);
}

void ponyOnTheStack()
{
    Pony pony("Apple jack");
}

int main()
{
    ponyOnTheHeap();
    ponyOnTheStack();
}