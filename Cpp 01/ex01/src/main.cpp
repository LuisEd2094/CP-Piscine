/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:55:15 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 10:55:16 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *horde = zombieHorde(9, "Zombie");
    
    for (int i = 0; i < 9; i++)
        horde[i].announce();

    delete [] horde;
    return (0);
}
