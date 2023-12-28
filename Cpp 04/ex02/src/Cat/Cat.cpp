/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:26:07 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:26:08 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
	: Animal("Cat"), m_brain(new Brain())
{
	std::cout << "Cat(void) constructor called" << std::endl;
}

Cat::Cat(std::string type)
	: Animal(type), m_brain(new Brain())
{
	std::cout << "Cat(\"" << type << "\") constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
	: Animal(other), m_brain(new Brain())
{
	std::cout << "Cat copy constructor called on " << other.m_type << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	this->m_brain = rhs.m_brain;
	this->m_type = rhs.m_type;
	std::cout << "Cat = operator called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete m_brain;
	std::cout << "Cat destructor called for " << this->m_type << std::endl;
}

Brain* Cat::getBrain() const
{
	return (this->m_brain);
}

void Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
