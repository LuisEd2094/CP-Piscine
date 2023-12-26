/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:59:26 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 10:59:31 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main(void)
{
    Harl harl;
    std::string complains[4]  = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};

    for (int i = 0; i < 4; i++){
        std::cout << complains[i] << ": " << std::endl;
        harl.complain(complains[i]);
    }
    return (0);

}

