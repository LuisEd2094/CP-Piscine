#include "Cat.hpp"

Cat::Cat(void)
	: Animal("Cat")
{
	std::cout << "Cat(void) constructor called" << std::endl;
}

Cat::Cat(std::string type)
	: Animal(type)
{
	std::cout << "Cat(\"" << type << "\") constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
	: Animal(other)
{
	std::cout << "Cat copy constructor called on " << other.m_type << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	this->m_type = rhs.m_type;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called for " << this->m_type << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}