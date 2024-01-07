/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:09:26 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:09:27 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	Cat		catOperator = *newCat;

	std::cout << "catOperator Cat Type: " << catOperator.getType() << std::endl;
	catOperator.makeSound();

	Cat copyCat(*newCat);

	std::cout << "copyCat Cat Type: " << copyCat.getType() << std::endl;
	copyCat.makeSound();


	delete newAnimal;
	delete newCat;
	delete newDog;
	delete wrongAnimal;
	delete wrongCat;

	std::cout << "copyCat Cat Type: " << copyCat.getType() << std::endl;
	copyCat.makeSound();
	std::cout << "catOperator Cat Type: " << catOperator.getType() << std::endl;
	catOperator.makeSound();
}
