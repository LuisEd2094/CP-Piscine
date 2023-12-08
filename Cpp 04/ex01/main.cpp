#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	/*Animal		*newAnimal = new Animal();
	Cat			*newCat = new Cat();
	Dog			*newDog = new Dog();*/
	Brain		*newBrain = new Brain();
	Brain		*anotherBrain = new Brain();

	*anotherBrain = *newBrain;

	std::cout << newBrain << std::endl<< anotherBrain << std::endl<< std::endl;

	for (int i = 0; i < 100; i++)
		std::cout << newBrain->getIdea(i) << std::endl;

	delete newBrain;
	std::cout << "ANOTHER BRAIN" << std::endl<< std::endl<< std::endl<< std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << anotherBrain->getIdea(i) << std::endl;
}