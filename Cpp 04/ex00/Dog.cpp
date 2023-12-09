#include "Dog.hpp"

Dog::Dog(void)
	: Animal("Dog")
{
	std::cout << "Dog(void) constructor called" << std::endl;
}

Dog::Dog(std::string type)
	: Animal(type)
{
	std::cout << "Dog(\"" << type << "\") constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	std::cout << "Dog copy constructor called on " << other.m_type << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	this->m_type = rhs.m_type;
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called for " << this->m_type << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Bark" << std::endl;
}