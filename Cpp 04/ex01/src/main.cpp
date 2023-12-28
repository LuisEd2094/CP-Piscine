/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:17:06 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:17:07 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"


void anotherTest(void)
{
	Animal* animals[10];
	
	for (int i = 0; i < 10; i++)
	{
		if (i >= 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << animals[i] << std::endl;
	}
	for (int i = 0; i < 5; i++)
	{
		Cat *copyCat = (Cat *)(animals[i]);
		for (int j = 0; j < 100; j++)
		{
			std::cout << copyCat->getBrain()->getIdea(j) << std::endl;
		}
		std::cout << "DONE WITH A CAT " << std::endl << std::endl;
	}

	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete animals[i];
	}
}

int main()
{
	//Animal		*newAnimal = new Animal();
	Cat			*newCat = new Cat();
	Cat			*anotherCat = new Cat(*newCat);

	for (int i = 0; i < 100; i++)
		std::cout << newCat->getBrain()->getIdea(i) << std::endl;
	delete newCat;

	for (int i = 0; i < 100; i++)
		std::cout << anotherCat->getBrain()->getIdea(i) << std::endl;

	std::cout << newCat << std::endl << anotherCat << std::endl;

	delete anotherCat;

	const Animal *animalCat = new Cat();
	const Animal *animalDog = new Dog();

	for (int i = 0; i < 100; i++)
		std::cout << ((Cat *)(animalCat))->getBrain()->getIdea(i) << std::endl;

	std::cout << ((Cat *)(animalCat))->getType() << std::endl;
	std::cout << animalCat->getType() << std::endl;

	animalCat->makeSound();
	((Cat *)(animalCat))->makeSound();
	animalDog->makeSound();
	((Dog *)(animalDog))->makeSound();

	delete animalCat;
	delete animalDog;
	//anotherTest();


}
