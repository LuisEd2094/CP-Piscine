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

AMateria::AMateria(void) : _type("default") {}
AMateria::AMateria(std::string const& type) : _type(type) {}
AMateria::AMateria(const AMateria& src): _type(src._type) {}

AMateria& AMateria::operator=(const AMateria& rhs)
{
    (void)rhs;
    return (*this);
}

AMateria::~AMateria() {}

std::string const& AMateria::getType(void) const
{
    return (_type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
