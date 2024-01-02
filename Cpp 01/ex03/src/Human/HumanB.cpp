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
    _name = name; 
    _weapon = NULL;
}

HumanB::~HumanB(void)
{
    
}

void HumanB::setWeapon(Weapon  &weapon)
{
    _weapon = &weapon;
}


void HumanB::attack(void)
{
    std::cout << _name << " attacks with their ";
    if (_weapon)
        std::cout << _weapon->getType();
    else
        std::cout << "fists";
    std::cout << std::endl;
}

