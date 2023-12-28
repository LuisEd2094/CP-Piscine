/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:30:08 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:30:09 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
class AMateria;

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource(void);
	    MateriaSource(const MateriaSource& other);
	
    	MateriaSource& operator=(const MateriaSource& rhs);
	    ~MateriaSource(void);

        void learnMateria(AMateria* m);
	    AMateria* createMateria(const std::string& type);

    private:
        AMateria*   m_materia[4];
};

#endif
