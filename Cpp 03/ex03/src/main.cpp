/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:05:53 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/28 10:05:55 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap daniel("Daniel");
	
	daniel.attack("Ned");
	daniel.takeDamage(5);
	daniel.beRepaired(3);
	daniel.guardGate();
	daniel.highFivesGuys();
	daniel.whoAmI();

	DiamondTrap copy(daniel);
	DiamondTrap equal("Equal");

	DiamondTrap to_test = equal;

	copy.beRepaired(10);
	daniel.beRepaired(0);
	to_test.attack("Maria");
	copy.attack("Pedro");
}
