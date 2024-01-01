/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:14:15 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 11:14:20 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;

    a = b;
    b = temp;
}

template <typename T>
T min(T a, T b)
{
    return ((a < b) ? a : b );
}

template <typename T>
T max(T a, T b)
{
    return ((a > b) ? a : b );
}
