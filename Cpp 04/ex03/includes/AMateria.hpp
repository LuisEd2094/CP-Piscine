/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:29:26 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:29:27 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria(void);
        AMateria(std::string const& type);
        AMateria(const AMateria& src);
        AMateria& operator=(const AMateria& rhs);
        std::string const& getType(void) const;

        virtual AMateria* clone(void) const = 0;
        virtual ~AMateria(void) = 0;
        virtual void use(ICharacter& target) = 0;
};

#endif
