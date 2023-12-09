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

	/*for (int i = 0; i < 100; i++)
		std::cout << newCat->getBrain()->getIdea(i) << std::endl;

	for (int i = 0; i < 100; i++)
		std::cout << anotherCat->getBrain()->getIdea(i) << std::endl;*/

	std::cout << newCat << std::endl << anotherCat << std::endl;

	delete newCat;
	delete anotherCat;

	anotherTest();


}