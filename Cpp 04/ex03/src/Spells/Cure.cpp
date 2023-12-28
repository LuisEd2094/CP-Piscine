/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:29:36 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:29:37 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
