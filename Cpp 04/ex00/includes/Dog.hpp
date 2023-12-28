/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:09:02 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:09:03 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog(void);
        Dog(std::string type);
        Dog(const Dog& other);
        Dog& operator=(const Dog& rhs);
        ~Dog(void);

        void makeSound(void) const;
};

#endif
