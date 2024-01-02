/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:29:44 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 13:29:45 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{

}

Point::Point(const float x, const float y): _x(x), _y(y)
{

}

Point::Point(const Point& point) : _x(point.getX()), _y(point.getY())
{

}

Point::~Point(void)
{
    
}
Point& Point::operator=(const Point& point)
{
    (void)point;
    std::cout << "Can't assign to const values. Values stay the same as with default constructor." << std::endl;
    return (*this);
 
}

Fixed const Point::getX(void) const
{
    return (_x);
}
Fixed const Point::getY(void) const
{
    return (_y);
}
