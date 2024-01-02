/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:08:52 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:08:53 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
	: Animal("Cat")
{
	std::cout << "Cat(void) constructor called" << std::endl;
}

Cat::Cat(std::string type)
	: Animal(type)
{
	std::cout << "Cat(\"" << type << "\") constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
	: Animal(other)
{
	std::cout << "Cat copy constructor called on " << other._type << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	_type = rhs._type;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called for " << _type << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
