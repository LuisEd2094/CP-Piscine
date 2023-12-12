#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}
Cure::Cure(std::string const& type) : AMateria(type) {}
Cure::~Cure(void){}

Cure::Cure(const Cure& other) : AMateria(other) {}

Cure& Cure::operator=(const Cure& rhs)
{
    if (this != &rhs)
    {
        this->m_type = rhs.m_type;
    } 
    return (*this);
}

AMateria* Cure::clone(void) const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() <<"'s wounds *" << std::endl;
}
