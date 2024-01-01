/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:34:09 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 11:34:09 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T, typename Func>
void iter (T* array, size_t size, Func function)
{
    for (size_t i = 0; i < size; ++i)
        function(array[i]);
}

template <typename T>
void print_element(const T& element) {
    std::cout << element << std::endl;
}
