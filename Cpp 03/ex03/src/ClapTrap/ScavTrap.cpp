/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:06:20 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:06:21 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
    : ClapTrap()
{
    std::cout << "Default ScavTrap constructor called" << std::endl;
    _hp = ScavTrap::_base_hp;
    _energy = ScavTrap::_base_energy;
    _dmg = ScavTrap::_base_dmg;
}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name)
{
    std::cout << "ScavTrap(name) constructor called, created ScavTrap " << _name << std::endl;
    _hp = ScavTrap::_base_hp;
    _energy = ScavTrap::_base_energy;
    _dmg = ScavTrap::_base_dmg;
}

ScavTrap::ScavTrap(const ScavTrap &toCocpy)
    : ClapTrap(toCocpy)
{
    std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
    ClapTrap::operator=(scavtrap);

    std::cout << "ScavTrap operator = called for " << _name << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap deconstructor called for " << _name << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
    std::cout << "Scavtrap "  << _name;
    if (!canTakeAction())
        std::cout << "He can't attack!" << std::endl;
    else
    {
        _energy -= 1;
        std::cout << " attacks " << target << ", causing " << _dmg << " points of damage!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name;
    if (!canTakeAction())
        std::cout << "He can't guard the gates!" << std::endl;
    else
    {
        _energy -= 1;
        std::cout << " has entered Gate keeper mode!" << std::endl;
    }
}
