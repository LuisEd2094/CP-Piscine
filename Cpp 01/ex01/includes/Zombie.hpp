/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:55:41 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 10:55:45 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>

class Zombie 
{
    private:
        std::string _name;
    public:
        Zombie() : _name("") {};
        ~Zombie(void);

        void    announce(void);
        void    setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
