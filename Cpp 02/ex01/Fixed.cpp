#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->m_fixedPoint = 0;
}

Fixed::Fixed(int const val)
{
	std::cout << "Int constructor called" << std::endl;
	this->m_fixedPoint = (val << Fixed::fraction);
}

Fixed::Fixed(float const val)
{
	std::cout << "Float constructor called" << std::endl;
	this->m_fixedPoint = int(roundf(val * (1 << Fixed::fraction)));
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

	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}



int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->m_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->m_fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return (float(this->m_fixedPoint) / (1 << Fixed::fraction));
}

int Fixed::toInt(void) const
{
	return (this->m_fixedPoint >> Fixed::fraction);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
