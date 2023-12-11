#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}
Ice::Ice(std::string const& type) : AMateria(type) {}
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

Ice* Ice::clone(void) const
{
    return new Ice(*this);
    Ice * newIce = new Ice();

    newIce->m_type = this->m_type;
    return (newIce);
}