/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:29:29 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:29:30 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void) 
	: _name("Default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string& name)
	: _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other)
	: _name(other._name)
{
	*this = other;
}

Character& Character::operator=(const Character& rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
        for (int i = 0; i < 4; i++)
		{
				if (_inventory[i])
					delete _inventory[i];
				_inventory[i] = ((rhs._inventory[i]) ? rhs._inventory[i] : NULL);
		}
    }
    return *this;
}

Character::~Character(void) 
{
        for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}

}

std::string const & Character::getName(void) const
{
	return (_name);
}

void Character::equip(AMateria* m)
{	
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!_inventory[i])
			{
				_inventory[i] = m;
				break;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (_inventory[idx])
	{
		AMateria::addToDropped(_inventory[idx]);
		_inventory[idx] = NULL;
	}
}


void Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx])
		_inventory[idx]->use(target);
}
