#include "Ice.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"


void testMateria(void)
{
    Ice iceMateria;
    Ice anotherice;
    Cure cure;
    Character myChar("My char");
    Character target("Target");

    myChar.equip(&iceMateria);
    myChar.equip(&anotherice);
    myChar.equip(&anotherice);
    myChar.equip(&anotherice);
    myChar.equip(&anotherice);

    myChar.equip(&cure);

    myChar.use(0, target);
    myChar.use(1, target);
    myChar.use(2,target);

    myChar.unequip(2);
    myChar.use(0, target);
    myChar.use(2, target);
    myChar.use(2,target);

    myChar.unequip(2);
    myChar.equip(&cure);
    myChar.use(0, target);
    myChar.use(2, target);
    myChar.use(2,target);
}

void pdfTest(void)
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
}

int main(void)
{
    //testMateria();
    pdfTest();
}