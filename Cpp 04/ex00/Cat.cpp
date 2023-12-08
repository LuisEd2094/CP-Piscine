#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << this->m_type << " constructor called" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << this->m_type << " destructor called" << std::endl;
}

void    Cat::makeSound( void ) const
{
    std::cout << "The cat goes: Meow!" << std::endl;
}