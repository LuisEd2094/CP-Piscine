/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:25:57 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:25:58 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string _type;
        Animal(void);
        Animal(std::string type);

        Animal(const Animal& src);
        Animal& operator=(const Animal& rhs);


    public:
        virtual ~Animal(void);

        virtual void    makeSound(void) const;
        std::string     getType(void) const; 
};

#endif
