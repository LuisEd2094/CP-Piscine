/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:08:59 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:09:00 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
	: Animal("Dog")
{
	std::cout << "Dog(void) constructor called" << std::endl;
}

Dog::Dog(std::string type)
	: Animal(type)
{
	std::cout << "Dog(\"" << type << "\") constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	std::cout << "Dog copy constructor called on " << other._type << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	_type = rhs._type;
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called for " << _type << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Bark" << std::endl;
}
