/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:56:25 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 09:56:30 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap john("John");
	ClapTrap jim("Jim");
	ClapTrap joe("Joe");

	john.attack("Marge");
	john.attack("Bart");
	john.attack("Homer");
	john.takeDamage(5);
	jim.takeDamage(9);
	jim.takeDamage(10);
	joe.beRepaired(10);
	joe.takeDamage(19);
	joe.takeDamage(19);
	joe.attack("Marge");
	joe.beRepaired(10);
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.attack("Marge");
	john.beRepaired(10);
}
