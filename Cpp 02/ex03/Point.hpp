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