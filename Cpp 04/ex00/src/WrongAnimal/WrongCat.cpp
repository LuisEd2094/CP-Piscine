/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:09:19 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:09:19 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
	: WrongAnimal("WrongCat")
{
	std::cout << "WrongCat(void) constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called on " << other._type << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	WrongAnimal::operator=(rhs);
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called for " << _type << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Bark" << std::endl;
}
