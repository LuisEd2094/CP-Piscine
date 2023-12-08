#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal		*newAnimal = new Animal();
	Cat			*newCat = new Cat();
	Dog			*newDog = new Dog();
	WrongAnimal	*wrongAnimal = new WrongAnimal();
	WrongCat	*wrongCat = new WrongCat();


	std::cout << "Animal Type: " << newAnimal->getType() << std::endl;
	std::cout << "Cat Type: " << newCat->getType() << std::endl;
	std::cout << "Dog Type: " << newDog->getType() << std::endl;
	std::cout << "wrongAnimal Type: " << wrongAnimal->getType() << std::endl;
	std::cout << "wrongCat Type: " << wrongCat->getType() << std::endl;

	newAnimal->makeSound();
	newCat->makeSound();
	newDog->makeSound();
	wrongAnimal->makeSound();
	wrongCat->makeSound();

	delete newAnimal;
	delete newCat;
	delete newDog;
	delete wrongAnimal;
	delete wrongCat;

}