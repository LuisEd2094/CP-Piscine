/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:39:09 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/02 09:39:11 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

template <typename T>
void easyfind (T& container, int value)
{
    if (std::find (container.begin(), container.end(), value) != container.end())
        std::cout << "Found." << std::endl;
    else 
        throw std::runtime_error("Value not found in container");
}

#endif
