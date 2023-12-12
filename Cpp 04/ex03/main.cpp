#include "Ice.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"


void testMateria(void)
{
    Ice iceMateria;
    Ice anotherice;
    Cure cure;
    Character myChar("My char");
    Character target("Target");

    myChar.equip(&iceMateria);
    myChar.equip(&anotherice);
    myChar.equip(&cure);

    myChar.use(0, target);
    myChar.use(1, target);
    myChar.use(2,target);

    myChar.unequip(2);
    myChar.use(0, target);
    myChar.use(2, target);
    myChar.use(2,target);
}

int main(void)
{
    testMateria();
}