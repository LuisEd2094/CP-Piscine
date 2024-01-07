/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:29:56 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:29:57 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <iostream>

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(const Ice& other);
        Ice& operator=(const Ice& rhs);
        ~Ice(void);

        void use(ICharacter& target);
	    AMateria* clone(void) const;
};

#endif
