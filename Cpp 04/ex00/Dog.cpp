#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << this->m_type << " constructor called" << std::endl;
}

Dog::~Dog(void)
{
    std::cout << this->m_type << " destructor called" << std::endl;
}

void    Dog::makeSound( void ) const
{
    std::cout << "The Dog goes: Bark!" << std::endl;
}