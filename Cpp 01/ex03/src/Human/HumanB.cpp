/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:57:33 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 10:57:37 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->m_name = name; 
    this->m_weapon = NULL;
}

HumanB::~HumanB(void)
{
    
}

void HumanB::setWeapon(Weapon  &weapon)
{
    this->m_weapon = &weapon;
}


void HumanB::attack(void)
{
    std::cout << this->m_name << " attacks with their ";
    if (this->m_weapon)
        std::cout << this->m_weapon->getType();
    else
        std::cout << "fists";
    std::cout << std::endl;
}

