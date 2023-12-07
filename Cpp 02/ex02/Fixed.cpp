#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->m_fixedPoint = 0;
}

Fixed::Fixed(int const val)
{
	this->m_fixedPoint = (val << Fixed::fraction);
}

Fixed::Fixed(float const val)
{
	this->m_fixedPoint = int(roundf(val * (1 << Fixed::fraction)));
}

Fixed::Fixed(const Fixed& toCopy)
{
	*this = toCopy; 
}

Fixed& Fixed::operator=(const Fixed& toCopy)
{
	this->m_fixedPoint = toCopy.getRawBits();

	return (*this);
}

Fixed::~Fixed(void)
{
}

bool    Fixed::operator<(const Fixed& fixed)
{
	return (this->m_fixedPoint < fixed.getRawBits());
}
bool    Fixed::operator>(const Fixed& fixed)
{
	return (this->m_fixedPoint > fixed.getRawBits());
}			
bool    Fixed::operator>=(const Fixed& fixed)
{
	return (this->m_fixedPoint >= fixed.getRawBits());
}		
bool    Fixed::operator<=(const Fixed& fixed)
{
	return (this->m_fixedPoint <= fixed.getRawBits());
}		
bool    Fixed::operator==(const Fixed& fixed)
{
	return (this->m_fixedPoint == fixed.getRawBits());
}		
bool    Fixed::operator!=(const Fixed& fixed)
{
	return (this->m_fixedPoint != fixed.getRawBits());
}


Fixed   Fixed::operator+(const Fixed& fixed)
{
	Fixed result;

	result.setRawBits(this->m_fixedPoint + fixed.getRawBits());
	return (result);

}		
Fixed   Fixed::operator-(const Fixed& fixed)
{
	Fixed result;

	result.setRawBits(this->m_fixedPoint - fixed.getRawBits());
	return (result);

}			
Fixed   Fixed::operator*(const Fixed& fixed)
{
	Fixed result;

	result.setRawBits(this->m_fixedPoint * fixed.getRawBits() >> Fixed::fraction);
	return (result);

}			
Fixed  Fixed::operator/(const Fixed& fixed)
{
	Fixed result;

	result.setRawBits(this->m_fixedPoint + ((1 << Fixed::fraction) / fixed.getRawBits()));
	return (result);

}

Fixed& Fixed::operator++()
{
	this->m_fixedPoint++;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->m_fixedPoint--;
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
	return (this->m_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
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
