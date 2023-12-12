#include "Ice.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"


void testMateria(void)
{
    Ice *iceMateria = new Ice();
    Ice *anotherice = new Ice();
    Cure *cure = new Cure();
    Character *myChar = new Character("My char");
    Character *target = new Character("Target");

    myChar->equip(iceMateria);
    myChar->equip(anotherice);
    myChar->equip(anotherice);
    myChar->equip(anotherice);
    myChar->equip(anotherice);

    myChar->equip(cure);

    myChar->use(0, *target);
    myChar->use(1, *target);
    myChar->use(2,*target);

    myChar->unequip(2);
    myChar->use(0, *target);
    myChar->use(2, *target);
    myChar->use(2,*target);

    myChar->unequip(2);
    myChar->equip(cure);
    myChar->use(0, *target);
    myChar->use(2, *target);
    myChar->use(2,*target);

    delete myChar;
    delete target;
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

void testM_type(void)
{
    /*
    Ice ice;
    Ice ice4;
    Ice ice2;
    ice2 = ice;
    Ice ice3(ice);
    AMateria* clone = ice3.clone();


    std::cout << &ice.m_type << " " << &ice2.m_type << " " << &ice3.m_type << std::endl;

    std::cout << ice.getType() << " " << ice2.getType() <<  " " << ice3.getType() << std::endl;

    std::cout << &clone->m_type << std::endl;*/
}

int main(void)
{
    testMateria();
    //pdfTest();
    //testM_type();
}