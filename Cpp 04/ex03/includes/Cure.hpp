/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:29:39 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:29:40 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <iostream>

class Cure : public AMateria
{
    public:
        Cure(void);
        Cure(std::string  const& type);
        Cure(const Cure& other);
        Cure& operator=(const Cure& rhs);
        ~Cure(void);

        void use(ICharacter& target);
	    AMateria* clone(void) const;

};


#endif
