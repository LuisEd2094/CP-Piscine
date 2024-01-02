/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:30:03 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:30:04 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"


MateriaSource::MateriaSource(void) 
{
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
		MateriaSource::learnMateria(other._materia[i]);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
		    MateriaSource::learnMateria(rhs._materia[i]);
    }
    return *this;
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i])
            delete _materia[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m)
    {
        for (int i = 0; i < 4; i++)
        {
            if (!_materia[i])
            {
                _materia[i] = m;
                break;
            }
        }
    }
}
AMateria* MateriaSource::createMateria(const std::string& type)
{
    if (!type.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            if (_materia[i]->getType() == type)
                return (_materia[i]->clone());
        }
    }
    return (0);
}
