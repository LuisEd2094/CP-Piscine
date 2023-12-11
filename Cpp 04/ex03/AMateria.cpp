#include "AMateria.hpp"

AMateria::AMateria(void) : m_type("default") {}
AMateria::AMateria(std::string const& type) : m_type(type) {}
AMateria::AMateria(const AMateria& src) : m_type(src.m_type) {}
AMateria& AMateria::operator=(const AMateria& rhs)
{
    if (this != &rhs)
        this->m_type = rhs.m_type;
    return (*this);
}

AMateria::~AMateria() {}

std::string const& AMateria::getType(void) const
{
    return (this->m_type);
}