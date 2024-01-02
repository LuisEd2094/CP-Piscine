/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:25:53 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:25:54 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
    std::cout << "Default Animal constructor  called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << "Animal(type) constructor called for " << type << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if ( this != &rhs ) 
    {
        _type = rhs._type;
    }
    return *this;
}
Animal::Animal(const Animal& src):
    _type(src._type)
{
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound(void) const
{
    std::cout << "Animal makeSound called" << std::endl;
}

std::string    Animal::getType(void) const
{
    return (_type);
}
