#include "Fixed.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	Fixed d = d;

	std::cout << d.getRawBits() << std::endl;

	return 0;
}