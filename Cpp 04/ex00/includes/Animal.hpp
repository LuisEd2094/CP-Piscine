/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:08:48 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:08:49 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string _type;

public:
    Animal(void);
    Animal(std::string type);
    virtual ~Animal(void);

    Animal(const Animal& src);
    Animal& operator=(const Animal& rhs);

    virtual void    makeSound(void) const;
    std::string     getType(void) const; 
};

#endif
