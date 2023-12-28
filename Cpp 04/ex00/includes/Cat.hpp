/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:08:56 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:08:56 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
class Cat : public Animal
{
    public:
        Cat(void);
        Cat(std::string type);
        Cat(const Cat& other);
        Cat& operator=(const Cat& rhs);
        ~Cat(void);

        void makeSound(void) const;
};

#endif
