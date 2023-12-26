/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:57:26 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 10:57:29 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : m_name(name), m_weapon(weapon)
{
}

HumanA::~HumanA(void)
{
    
}

void HumanA::attack(void)
{
    std::cout << this->m_name << " attacks with their " << this->m_weapon.getType() << std::endl;
}

