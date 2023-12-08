#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
    std::cout << this->m_type << " constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << this->m_type << " destructor called" << std::endl;
}

void    WrongCat::makeSound( void ) const
{
    std::cout << "The WrongCat goes: Bark!" << std::endl;
}