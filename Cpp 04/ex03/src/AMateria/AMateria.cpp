/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:29:21 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:29:22 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
