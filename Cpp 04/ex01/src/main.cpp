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

void dog_test(void)
{
	Dog *newDog2 = new Dog();
	Dog *copyDog = new Dog(*newDog2);
	Dog DogOperator = *copyDog;

	Dog * dog = new Dog();
	Dog dog2;

	dog2 = *dog;
	
	std::cout << dog->getBrain()->getIdea(0) << std::endl;
	std::cout << dog2.getBrain()->getIdea(0) << std::endl;

		std::cout << std::endl;


	delete dog;

	std::cout << dog2.getBrain()->getIdea(0) << std::endl;

	Dog cpyDog(*newDog2);

	delete newDog2;

	for (int i = 0; i < 100; i++)
		std::cout << copyDog->getBrain()->getIdea(i) << std::endl;
	delete copyDog;

	std::cout << "\t COPY DONE \t STARTING WITH CAT OPERATOR" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << DogOperator.getBrain()->getIdea(i) << std::endl;	
}

void cat_test(void)
{
	Cat *newCat2 = new Cat();
	Cat *copyCat = new Cat(*newCat2);
	Cat catOperator = *copyCat;
	Cat * cat = new Cat();
	Cat cat2;

	cat2 = *cat;
	
	std::cout << cat->getBrain()->getIdea(0) << std::endl;
	std::cout << cat2.getBrain()->getIdea(0) << std::endl;

	delete cat;

	std::cout << cat2.getBrain()->getIdea(0) << std::endl;




	Cat cpy(*newCat2);

	delete newCat2;

	for (int i = 0; i < 100; i++)
		std::cout << copyCat->getBrain()->getIdea(i) << std::endl;
	delete copyCat;

	std::cout << "\t COPY DONE \t STARTING WITH CAT OPERATOR" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << catOperator.getBrain()->getIdea(i) << std::endl;
}

void basic_test(void)
{
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
}

void array_test(void)
{
	Animal *animal_array[10];

	for (int i = 0; i < 5; ++i)
		animal_array[i] = new Cat();
	for (int i = 5; i < 10; ++i)
		animal_array[i] = new Dog();
	for (int i = 0; i < 10; ++i)
		animal_array[i]->makeSound();
	std::cout << ((Cat *)(animal_array[0]))->getBrain()->getIdea(0) << std::endl;
	std::cout << ((Dog *)(animal_array[9]))->getBrain()->getIdea(0) << std::endl;

	((Dog *)(animal_array[0]))->makeSound(); //Its a cat, even if ou type cast it it'd stil call the correct funnction
	for (int i = 0; i < 10; ++i)
		delete animal_array[i];
}

int main()
{
	//Animal		*newAnimal = new Animal();
	array_test();
	basic_test();
	anotherTest();
	cat_test();
	dog_test();
}
