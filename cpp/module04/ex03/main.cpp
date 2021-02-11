#include "Character.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(NULL);
    ICharacter* me = new Character("me");
    AMateria* tmp;
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("ice"));
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("cure"));
    ICharacter* bob = new Character("bob");
    Ice *ice = new Ice;
    bob->equip(ice);
    std::cout << ice->getXP() << std::endl;
    bob->use(0, *me);
    std::cout << ice->getXP() << std::endl;
    AMateria *ice2 = ice->clone();
    bob->equip(ice2);
    std::cout << ice2->getXP() << std::endl;
    bob->use(1, *me);
    std::cout << ice2->getXP() << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(1, *bob);
    me->use(5, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}