/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:26:13 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:26:14 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
	: Animal("Dog"), m_brain(new Brain())
{
	std::cout << "Dog(void) constructor called" << std::endl;
}

Dog::Dog(std::string type)
	: Animal(type), m_brain(new Brain())
{
	std::cout << "Dog(\"" << type << "\") constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	std::cout << "Dog copy constructor called on " << other.m_type << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	this->m_brain = rhs.m_brain;
	this->m_type = rhs.m_type;
	std::cout << "Dog = operator called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete m_brain;
	std::cout << "Dog destructor called for " << this->m_type << std::endl;
}

Brain* Dog::getBrain() const
{
	return (this->m_brain);
}

void Dog::makeSound(void) const
{
	std::cout << "Bark" << std::endl;
}
