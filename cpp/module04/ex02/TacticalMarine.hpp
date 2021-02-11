#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
    public:
        TacticalMarine();
        ~TacticalMarine();
        TacticalMarine(TacticalMarine const &);
        void operator=(TacticalMarine &tacticalMarine);
        TacticalMarine *clone() const;
        void battleCry() const;
        void rangedAttack() const;
        void meleeAttack() const;
};

#endif