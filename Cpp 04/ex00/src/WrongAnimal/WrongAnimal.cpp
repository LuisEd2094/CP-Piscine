/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:09:09 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:09:10 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : m_type("WrongAnimal")
{
    std::cout << "Default WrongAnimal constructor  called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : m_type(type)
{
    std::cout << "WrongAnimal(type) constructor called for " << type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if ( this != &rhs ) 
    {
        this->m_type = rhs.m_type;
    }
    return *this;
}
WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = src; 
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal makeSound called" << std::endl;
}

std::string    WrongAnimal::getType(void) const
{
    return (this->m_type);
}
