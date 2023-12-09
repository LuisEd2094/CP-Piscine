#include "WrongCat.hpp"

WrongCat::WrongCat(void)
	: WrongAnimal("WrongCat")
{
	std::cout << "WrongCat(void) constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type)
	: WrongAnimal(type)
{
	std::cout << "WrongCat(\"" << type << "\") constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called on " << other.m_type << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	this->m_type = rhs.m_type;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called for " << this->m_type << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}