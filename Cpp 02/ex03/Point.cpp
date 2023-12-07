#include "Point.hpp"

Point::Point(void) : m_x(0), m_y(0)
{

}

Point::Point(const float x, const float y): m_x(x), m_y(y)
{

}

Point::Point(const Point& point) : m_x(point.getX()), m_y(point.getY())
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
    return (this->m_x);
}
Fixed const Point::getY(void) const
{
    return (this->m_y);
}
