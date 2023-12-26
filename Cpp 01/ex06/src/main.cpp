/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:00:28 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 11:00:30 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char ** argv)
{
	Harl harl;

	if (argc == 2)
	{
		std::string levels[4] = {
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR"
		};
		int i = 0;
		while (i < 4 && levels[i] != argv[1])
			i++;
		switch (i)
		{
			case 0:
				std::cout << "[ " << levels[0] << " ]" << std::endl;
				harl.complain(levels[0]);
				std::cout << std::endl;
                // fall through
			case 1:
				std::cout << "[ " << levels[1] << " ]" << std::endl;
				harl.complain(levels[1]);
				std::cout << std::endl;
                // fall through
			case 2:
				std::cout << "[ " << levels[2] << " ]" << std::endl;
				harl.complain(levels[2]);
				std::cout << std::endl;
                // fall through
			case 3:
				std::cout << "[ " << levels[3] << " ]" << std::endl;
				harl.complain(levels[3]);
				std::cout << std::endl;
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
	}
}

