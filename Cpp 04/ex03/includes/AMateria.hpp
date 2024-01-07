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


struct Node {
        AMateria *materia;
        Node *next;
        };
class AMateria
{
    protected:
        std::string _type;
        AMateria(void);
        AMateria(std::string const& type);
        AMateria(const AMateria& src);
        AMateria& operator=(const AMateria& rhs);
        static Node* list;
        static Node* curr;
    public:
        std::string const& getType(void) const;

        virtual AMateria* clone(void) const = 0;
        virtual ~AMateria(void);
        virtual void use(ICharacter& target);

        static Node *getMateriaList(void);
        static void addToDropped(AMateria *materia);
        static void cleanList(void);

private:

    // Static member to keep track of all created AMateria instances
};



#endif
