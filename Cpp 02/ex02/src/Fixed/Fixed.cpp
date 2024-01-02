/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:25:34 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 13:25:35 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	_fixedPoint = 0;
}

Fixed::Fixed(int const val)
{
	_fixedPoint = (val << Fixed::fraction);
}

Fixed::Fixed(float const val)
{
	_fixedPoint = int(roundf(val * (1 << Fixed::fraction)));
}

Fixed::Fixed(const Fixed& toCopy)
{
	*this = toCopy; 
}

Fixed& Fixed::operator=(const Fixed& toCopy)
{
	if (this != &toCopy)
		_fixedPoint = toCopy.getRawBits();

	return (*this);
}

Fixed::~Fixed(void)
{
}

bool    Fixed::operator<(const Fixed& fixed)
{
	return (_fixedPoint < fixed.getRawBits());
}
bool    Fixed::operator>(const Fixed& fixed)
{
	return (_fixedPoint > fixed.getRawBits());
}			
bool    Fixed::operator>=(const Fixed& fixed)
{
	return (_fixedPoint >= fixed.getRawBits());
}		
bool    Fixed::operator<=(const Fixed& fixed)
{
	return (_fixedPoint <= fixed.getRawBits());
}		
bool    Fixed::operator==(const Fixed& fixed)
{
	return (_fixedPoint == fixed.getRawBits());
}		
bool    Fixed::operator!=(const Fixed& fixed)
{
	return (_fixedPoint != fixed.getRawBits());
}


Fixed   Fixed::operator+(const Fixed& fixed)
{
	Fixed result;

	result.setRawBits(_fixedPoint + fixed.getRawBits());
	return (result);

}		
Fixed   Fixed::operator-(const Fixed& fixed)
{
	Fixed result;

	result.setRawBits(_fixedPoint - fixed.getRawBits());
	return (result);

}			
Fixed   Fixed::operator*(const Fixed& fixed)
{
	Fixed result;

	result.setRawBits(_fixedPoint * fixed.getRawBits() >> Fixed::fraction);
	return (result);

}			
Fixed  Fixed::operator/(const Fixed& fixed)
{
	Fixed result;

	result.setRawBits(_fixedPoint + ((1 << Fixed::fraction) / fixed.getRawBits()));
	return (result);

}

Fixed& Fixed::operator++()
{
	_fixedPoint++;
	return *this;
}

Fixed& Fixed::operator--()
{
	_fixedPoint--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++*this;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--*this;
	return tmp;
}


int Fixed::getRawBits(void) const
{
	return (_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return (float(_fixedPoint) / (1 << Fixed::fraction));
}

int Fixed::toInt(void) const
{
	return (_fixedPoint >> Fixed::fraction);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return b;
	return a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a < b)
		return b;
	return a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return b;
	return a;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
