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
    : ClapTrap(), FragTrap(), ScavTrap(), _name("default")
{
    std::cout << "Default DiamondTrap constructor called" << std::endl;
    ClapTrap::_name = ClapTrap::_name + "_clap_name";
    _hp = FragTrap::_base_hp;
    _energy = ScavTrap::_base_energy;
    _dmg = FragTrap::_base_dmg;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name" ), FragTrap(), ScavTrap(), _name(name)
{
    std::cout << "DiamondTrap(name) constructor called, created DiamondTrap " << _name << std::endl;
    _hp = FragTrap::_base_hp;
    _energy = ScavTrap::_base_energy;
    _dmg = FragTrap::_base_dmg;
}

DiamondTrap::DiamondTrap(const DiamondTrap &toCocpy)
    : ClapTrap(toCocpy), FragTrap(toCocpy), ScavTrap(toCocpy)
{
    *this = toCocpy;
    std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &DiamondTrap)
{
    std::cout << "DiamondTrap operator = called for " << _name << std::endl;
    if (this != &DiamondTrap)
    {
        ClapTrap::operator=(DiamondTrap);
        ClapTrap::_name = DiamondTrap._name + "_clap_name";
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
    std::cout << " whoAmI(): I am DiamondTrap " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
