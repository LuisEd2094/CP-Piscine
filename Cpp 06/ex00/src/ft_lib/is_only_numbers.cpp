/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_numbers.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:53:43 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:53:44 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.hpp"

bool is_only_numbers(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}
