/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:19:55 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 13:19:56 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->m_fixedPoint = 0;
}

Fixed::Fixed(const Fixed& toCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy; 
}

Fixed& Fixed::operator=(const Fixed& toCopy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &toCopy)
		this->m_fixedPoint = toCopy.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}



int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->m_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->m_fixedPoint = raw;
}
