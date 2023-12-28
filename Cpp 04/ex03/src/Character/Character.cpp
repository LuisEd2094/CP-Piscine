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
	: m_name("Default")
{
	for (int i = 0; i < 4; i++)
		this->m_inventory[i] = NULL;
}

Character::Character(const std::string& name)
	: m_name(name)
{
	for (int i = 0; i < 4; i++)
		this->m_inventory[i] = NULL;
}

Character::Character(const Character& other)
	: m_name(other.m_name)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->m_inventory[i])
			delete this->m_inventory[i];
		this->m_inventory[i] = (other.m_inventory[i]) ? other.m_inventory[i]->clone() : NULL;
	}
}

Character& Character::operator=(const Character& rhs)
{
    if (this != &rhs)
    {
        this->m_name = rhs.m_name;
        for (int i = 0; i < 4; i++)
		{
				if (this->m_inventory[i])
					delete this->m_inventory[i];
				this->m_inventory[i] = (rhs.m_inventory[i]) ? rhs.m_inventory[i]->clone() : NULL;
		}
    }
    return *this;
}

Character::~Character(void) 
{
        for (int i = 0; i < 4; i++)
		{
			if (this->m_inventory[i])
			{
				delete this->m_inventory[i];
				this->m_inventory[i] = NULL;
			}
		}

}

std::string const & Character::getName(void) const
{
	return (this->m_name);
}

void Character::equip(AMateria* m)
{	
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!this->m_inventory[i])
			{
				this->m_inventory[i] = m;
				break;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (this->m_inventory[idx])
		this->m_inventory[idx] = NULL;
}


void Character::use(int idx, ICharacter& target)
{
	if (this->m_inventory[idx])
		this->m_inventory[idx]->use(target);
}
