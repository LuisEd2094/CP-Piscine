/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:06:10 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:06:14 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
    : ClapTrap("default_clap_name"), FragTrap("default"), ScavTrap("default"), _name("default")
{
    std::cout << "Default DiamondTrap constructor called" << std::endl;
    FragTrap::_hp = 100;
    ScavTrap::_energy = 50;
    FragTrap::_dmg = 30;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name) , FragTrap(name) , ScavTrap(name)
{
	std::cout << "DiamondTrap(name) constructor called, created DiamondTrap" << _name << std::endl;
    _name = name;
    ClapTrap::_name = name + "_clap_name";
    FragTrap::_hp = 100;
    ScavTrap::_energy = 50;
    FragTrap::_dmg = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& toCocpy)
    : ClapTrap(toCocpy) , FragTrap(toCocpy) , ScavTrap(toCocpy)
{
    std::cout << "DiamondTrap copy constructor called for " << _name << std::endl; 
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& DiamondTrap)
{
    std::cout << "DiamondTrap operator = called for " << _name << std::endl;
    if (this != &DiamondTrap)
    {
        ClapTrap::operator=(DiamondTrap);
        ScavTrap::operator=(DiamondTrap);
        FragTrap::operator=(DiamondTrap);
        std::cout << "Operator = done" << std::endl;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap deconstructor called for " << _name << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap " << _name;
    if (!ClapTrap::canTakeAction())
        std::cout << "He can't guard the gates!" << std::endl;
    else
    {
        _energy -= 1;
	    std::cout << "whoAmI(): I am DiamondTrap " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
    }
}
