/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:29:27 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 13:29:28 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


float area(Point const a, Point const b, Point const c)
{
	return (std::abs(((a.getX().toInt() * (b.getY().toInt() - c.getY().toInt())) +\
    (b.getX().toInt() * (c.getY().toInt() - a.getY().toInt())) +\
    (c.getX().toInt() * (a.getY().toInt() - b.getY().toInt() ))) / 2.0));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float   d1, d2, d3, d4;

    d1 = area(a, b, c);
    d2 = area(point, b, c);
    d3 = area(a, point, c);
    d4 = area(a, b, point);


    return (d1 == (d2 + d3 + d4));
}
