/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:56:36 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 09:56:37 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) 
	: m_name("Default"), m_hp(10), m_energy(10),  m_dmg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
	: m_name(name), m_hp(10), m_energy(10),  m_dmg(0)
{
	std::cout << "Constructor with name called, created " << name << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap& toCopy) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy; 
}

ClapTrap& ClapTrap::operator=(const ClapTrap& toCopy)
{
	if (this != &toCopy)
	{
		this->m_name = toCopy.m_name;
		this->m_hp = toCopy.m_hp;
		this->m_energy = toCopy.m_energy;
		this->m_dmg = toCopy.m_dmg;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called on " << this->m_name << std::endl;
}

bool	ClapTrap::canTakeAction(void)
{
	bool canTake = 1;

	if (this->m_energy <= 0 || this->m_hp <= 0)
	{
		canTake = 0;
		if (this->m_energy <= 0 && this->m_hp <= 0)
			std::cout << " is out of energy AND he is dead! ";
		else if (this->m_energy <= 0)
			std::cout << " is out of energy! ";
		else if (this->m_hp <= 0)
			std::cout << " is out of hp! " ;
	}
	return (canTake);
}
 

void    ClapTrap::attack(std::string const& target)
{
	std::cout << "ClapTrap " << this->m_name;
	if (!canTakeAction())
		std::cout << "He can't attack!" << std::endl;
	else
	{
		this->m_energy -= 1;
		std::cout << " attacks " << target << ", causing " << this->m_dmg << " points of damage!" << std::endl;

	}
}
void    ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->m_name;
	if (!canTakeAction())
		std::cout << "He can't repair himself!" << std::endl;
	else
	{
		this->m_energy -= 1;
		this->m_hp += amount;
		std::cout << " healed himself for " << amount << " points! " << "He has now " << this->m_hp << " HP!" << std::endl;
	}
}


void    ClapTrap::takeDamage(unsigned int amount)
{
	if (this->m_hp <= amount)
		this->m_hp = 0;
	else
		this->m_hp -= amount;

	std::cout << this->m_name << " took " << amount << " points of damage!" << std::endl;	
	if (this->m_hp <= 0)
		std::cout << this->m_name << " died!" << std::endl;
}
