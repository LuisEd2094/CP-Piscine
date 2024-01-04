/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:00:04 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:00:05 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
    : ClapTrap()
{
    std::cout << "Default FragTrap constructor called" << std::endl;
    _hp = 100;
    _energy = 100;
    _dmg = 30;
}

FragTrap::FragTrap(std::string name)
    : ClapTrap(name)
{
    std::cout << "FragTrap(name) constructor called, created FragTrap" << _name << std::endl;
    _hp = 100;
    _energy = 100;
    _dmg = 30;
}

FragTrap::FragTrap(const FragTrap &toCocpy)
    : ClapTrap(toCocpy)
{
    std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &FragTrap)
{
    ClapTrap::operator=(FragTrap);

    std::cout << "FragTrap operator = called for " << _name << std::endl;
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap deconstructor called for " << _name << std::endl;
}

void FragTrap::attack(std::string const &target)
{
    std::cout << "FragTrap " << _name;
    if (!ClapTrap::canTakeAction())
        std::cout << "He can't attack!" << std::endl;
    else
    {
        _energy -= 1;
        std::cout << " attacks " << target << ", causing " << _dmg << " points of damage!" << std::endl;
    }
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name;
    if (!ClapTrap::canTakeAction())
        std::cout << "He can't give you a high five!" << std::endl;
    else
    {
        _energy -= 1;
        std::cout << " high fives everyone!" << std::endl;
    }
}
