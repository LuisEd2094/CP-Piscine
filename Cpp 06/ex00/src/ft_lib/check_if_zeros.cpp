/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_zeros.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:52:57 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:52:59 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.hpp"

bool        check_if_only_zeros(const std::string &str)
{
	std::string::const_iterator  it;
	
	for (it = str.begin(); it < str.end(); it++)
    {
        if (*it != '0')
            return (0);
    } 
	return (!str.empty());
}
