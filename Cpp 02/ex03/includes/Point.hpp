/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:29:24 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 13:29:24 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
class Point
{
    public:
        Point(void);
        Point(const float x, const float y);
        Point(const Point& point);
        ~Point(void);

        Point& operator=(const Point& point);

        Fixed const getX(void) const;
        Fixed const getY(void) const;
    
    private:
        Fixed const m_x;
        Fixed const m_y;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
