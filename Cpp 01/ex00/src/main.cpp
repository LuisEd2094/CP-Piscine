/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:54:17 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 10:54:19 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie* zombie1;
    Zombie  zombie2("Zombie 2");;


    zombie1 = newZombie("Zombie 1");
    zombie1->announce();
    delete zombie1;


    zombie2.announce();

    randomChump("Random");
    return (0);
}
