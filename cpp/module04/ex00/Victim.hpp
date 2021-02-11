#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>
#include <string>

class Victim
{
    public:
        Victim(std::string name);
        virtual ~Victim();
        virtual void selfIntroducing();
        Victim(Victim &vict);
        virtual std::string introducingString();
        virtual void getPolymorphed() const;
        void operator =(Victim &victim);
    protected:
        std::string _name;
    private:
        Victim();
};

std::ostream& operator<< (std::ostream& is, Victim &victim);

#endif