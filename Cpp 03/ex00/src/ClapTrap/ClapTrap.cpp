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
	: _name("Default"), _hp(10), _energy(10), _dmg(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hp(10), _energy(10), _dmg(0)
{
	std::cout << "Constructor with name called, created " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &toCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &toCopy)
{
	if (this != &toCopy)
	{
		_name = toCopy._name;
		_hp = toCopy._hp;
		_energy = toCopy._energy;
		_dmg = toCopy._dmg;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called on " << _name << std::endl;
}

bool ClapTrap::canTakeAction(void)
{
	bool canTake = 1;

	if (_energy <= 0 || _hp <= 0)
	{
		canTake = 0;
		if (_energy <= 0 && _hp <= 0)
			std::cout << " is out of energy AND he is dead! ";
		else if (_energy <= 0)
			std::cout << " is out of energy! ";
		else if (_hp <= 0)
			std::cout << " is out of hp! ";
	}
	return (canTake);
}

void ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << _name;
	if (!canTakeAction())
		std::cout << "He can't attack!" << std::endl;
	else
	{
		_energy -= 1;
		std::cout << " attacks " << target << ", causing " << _dmg << " points of damage!" << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name;
	if (!canTakeAction())
		std::cout << "He can't repair himself!" << std::endl;
	else
	{
		_energy -= 1;
		_hp += amount;
		std::cout << " healed himself for " << amount << " points! "
				  << "He has now " << _hp << " HP!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp <= amount)
		_hp = 0;
	else
		_hp -= amount;

	std::cout << _name << " took " << amount << " points of damage!" << std::endl;
	if (_hp <= 0)
		std::cout << _name << " died!" << std::endl;
}
