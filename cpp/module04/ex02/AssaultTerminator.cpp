#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
    std::cout << "* teleports from space *\n";
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &)
{
    std::cout << "* teleports from space *\n";
}

AssaultTerminator &AssaultTerminator::operator=(AssaultTerminator const &)
{
    return *this;
}

AssaultTerminator::~AssaultTerminator()
{
    std::cout << "I’ll be back...\n";
}

AssaultTerminator* AssaultTerminator::clone() const
{
    return new AssaultTerminator(*this);
}

void AssaultTerminator::rangedAttack() const
{
    std::cout << "* does nothing *\n";
}

void AssaultTerminator::battleCry() const
{
    std::cout << "This code is unclean. PURIFY IT!\n";
}

void AssaultTerminator::meleeAttack() const
{
    std::cout << "* attacks with chainfists *\n";
}