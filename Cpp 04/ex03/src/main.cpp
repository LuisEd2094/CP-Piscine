/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:30:29 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:30:30 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    //Cure *cure = new Cure();
    Character *myChar = new Character("My char");
    Character *target = new Character("Target");

    myChar->equip(iceMateria);
    myChar->equip(anotherice);
    myChar->equip(anotherice);
    myChar->equip(anotherice);
    myChar->equip(anotherice);

    //myChar->equip(cure);

    myChar->use(0, *target);
    myChar->use(1, *target);
    myChar->use(2,*target);

    myChar->unequip(2);
    myChar->use(0, *target);
    myChar->use(2, *target);
    myChar->use(2,*target);

    myChar->unequip(2);
    //myChar->equip(cure);
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


void ice_test_create(void)
{
    Ice ic1;
    Ice ic2 = ic1;
    Ice ic3(ic1);
    Ice ice4 = ic2  = ic3;
    Character *target = new Character("Target");

    Ice test;
    Ice test2;

    test2 = test;

    std::cout << test.getType() << std::endl;
    std::cout << test2.getType() << std::endl;
    

    ic1.use(*target);

    ic2.use(*target);

    ic3.use(*target);
    ice4.use(*target);

    std::cout << ic1.getType() << std::endl;
    std::cout << ic2.getType() << std::endl;
    std::cout << ic3.getType() << std::endl;
    std::cout << ice4.getType() << std::endl;

    delete target;

}

void cure_test_create(void)
{
    Character *target = new Character("Target");
    Cure cure1;
    Cure cure2 = cure1;
    Cure cure3(cure1);
    Cure cure4 = cure2  = cure3;

    Cure curetest;
    Cure curetest2;

    curetest2 = curetest;

    std::cout << curetest.getType() << std::endl;
    std::cout << curetest2.getType() << std::endl;
    

    cure1.use(*target);

    cure2.use(*target);

    cure3.use(*target);
    cure4.use(*target);
    std::cout << cure1.getType() << std::endl;
    std::cout << cure2.getType() << std::endl;
    std::cout << cure3.getType() << std::endl;
    std::cout << cure4.getType() << std::endl;


    delete target;
}


void character_test(void)
{
    Character * daniel = new Character("Daniel");
    Character * juan =  new Character("Juan");
    Character target("target");
    Ice * ice = new Ice();

    daniel->equip(ice);

    std::cout << daniel->getName() << std::endl;
    std::cout << juan->getName() << std::endl;
    daniel->use(0, *juan);

    juan = daniel;
    std::cout << daniel->getName() << std::endl;
    std::cout << juan->getName() << std::endl;

    juan->use(0, target);
   
    juan->use(0, target);
    delete daniel;
    juan->use(0, target);
    
    std::cout << juan->getName() << std::endl;


}

int main(void)
{
    //testMateria();
    //pdfTest();


    //ice_test_create();
    //cure_test_create();
    character_test();
    

}
