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
    this->m_hp = 100;
    this->m_energy = 100;
    this->m_dmg = 30;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	std::cout << "FragTrap(name) constructor called, created FragTrap" << this->m_name << std::endl;
    this->m_hp = 100;
    this->m_energy = 100;
    this->m_dmg = 30;
}

FragTrap::FragTrap(const FragTrap& toCocpy)
    : ClapTrap(toCocpy)
{
    std::cout << "FragTrap copy constructor called for " << this->m_name << std::endl; 
}

FragTrap& FragTrap::operator=(const FragTrap& FragTrap)
{
    ClapTrap::operator=(FragTrap);

    std::cout << "FragTrap operator = called for " << this->m_name << std::endl;
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap deconstructor called for " << this->m_name << std::endl;
}


void FragTrap::attack(std::string const& target)
{
    std::cout << "FragTrap " << this->m_name;
    if (!ClapTrap::canTakeAction())
        std::cout << "He can't attack!" << std::endl;
    else
    {
        this->m_energy -= 1;
        std::cout << " attacks " << target << ", causing " << this->m_dmg << " points of damage!" << std::endl;

    }
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->m_name;
    if (!ClapTrap::canTakeAction())
        std::cout << "He can't give you a high five!" << std::endl;
    else
    {
        this->m_energy -= 1;
	    std::cout << " high fives everyone!" << std::endl;
    }
}
