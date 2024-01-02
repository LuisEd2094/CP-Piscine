/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:54:48 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 10:54:50 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie 
{
    private:
        std::string _name;
    public:
        Zombie(std::string name);
        ~Zombie(void);

        void announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
