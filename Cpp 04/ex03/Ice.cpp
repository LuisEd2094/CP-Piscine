#include "Ice.hpp"

std::string Ice::m_type = "ice";

Ice::Ice(void) : AMateria("ice") {}
Ice::~Ice(void){}

Ice::Ice(const Ice& other) : AMateria(other) {}

Ice& Ice::operator=(const Ice& rhs)
{
    if (this != &rhs)
    {
        this->m_type = rhs.m_type;
    } 
    return (*this);
}

AMateria* Ice::clone(void) const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
