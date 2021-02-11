#include "Squad.hpp"

Squad::Squad()
{
    spaceMarines = new ISpaceMarine*[1];
    spaceMarines[0] = NULL;
}

int Squad::getCount() const
{
    int i = 0;
    while (spaceMarines[i])
        i++;
    return (i);
}

void Squad::operator=(Squad &squad)
{
    delete spaceMarines;
    spaceMarines = new ISpaceMarine*[squad.getCount() + 1];
    int i = 0;
    while (squad.spaceMarines[i])
    {
        if (squad.spaceMarines[i] != NULL)
            spaceMarines[i] = squad.spaceMarines[i]->clone();
        i++;
    }
}

Squad::Squad(Squad &squad)
{
    *this = squad;
}

ISpaceMarine *Squad::getUnit(int x) const
{
    int i = 0;
    while (spaceMarines[i])
    {
        if (i == x)
            return (spaceMarines[i]);
        i++;
    }
    return (NULL);
}

Squad::~Squad()
{
    for (int i = 0; i < getCount(); i++)
        delete this->spaceMarines[i];
}

int Squad::push(ISpaceMarine *iSpaceMarine)
{
    int addFlag = 1;
    if (iSpaceMarine == NULL)
        addFlag = 0;
    int i = 0;
    while (spaceMarines[i])
    {
        if (spaceMarines[i] == iSpaceMarine)
            addFlag = 0;
        i++;
    }
    ISpaceMarine **oldSpaceMarine = spaceMarines;
    int oldCount = getCount();
    spaceMarines = new ISpaceMarine*[i + 2];
    for (int j = 0; j < oldCount; j++)
        spaceMarines[j] = oldSpaceMarine[j];
    if (addFlag)
        spaceMarines[i] = iSpaceMarine;
    spaceMarines[i + 1] = NULL;
    return (i);
}