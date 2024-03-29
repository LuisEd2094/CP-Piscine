/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:16:44 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:16:46 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
	: Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat(void) constructor called" << std::endl;
}



Cat::Cat(const Cat& other)
	: Animal(other), _brain(new Brain(*other._brain))
{
	std::cout << "Cat copy constructor called on " << other._type << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	Animal::operator=(rhs);
	*_brain = *rhs._brain;
	std::cout << "Cat = operator called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destructor called for " << _type << std::endl;
}

Brain* Cat::getBrain() const
{
	return (_brain);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
