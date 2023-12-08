#include "Animal.hpp"

Animal::Animal(void) : m_type("Animal")
{
    std::cout << "Default Animal constructor  called" << std::endl;
}

Animal::Animal(std::string type) : m_type(type)
{
    std::cout << "Animal(type) constructor called for " << type << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if ( this != &rhs ) 
    {
        this->m_type = rhs.m_type;
    }
    return *this;
}
Animal::Animal(const Animal& src)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src; 
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound(void) const
{
    std::cout << "Animal makeSound called" << std::endl;
}

std::string    Animal::getType(void) const
{
    return (this->m_type);
}