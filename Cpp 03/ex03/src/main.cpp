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

	std::cout << daniel << std::endl;

	daniel.ScavTrap::attack("Pedro");
	daniel.FragTrap::attack("Maria");
	daniel.attack("Ned");
	daniel.takeDamage(5);
	daniel.beRepaired(3);
	daniel.guardGate();
	daniel.highFivesGuys();
	daniel.whoAmI();
}
