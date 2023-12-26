/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:57:45 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 10:57:51 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    m_type = type;
}

Weapon::~Weapon(void)
{
}

void Weapon::setType(std::string type)
{
    m_type = type;
}

const std::string& Weapon::getType(void)
{
    return m_type;
}

