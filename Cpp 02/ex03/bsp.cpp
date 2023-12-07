#include "Point.hpp"


float sign(Point const point, Point const a, Point const b)
{
	return ((point.getX().toFloat() - b.getX().toFloat()) *\
    (a.getY().toFloat() - b.getY().toFloat()) -\
    (a.getX().toFloat() - b.getX().toFloat()) *\
    (point.getY().toFloat() - b.getY().toFloat()));
}
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float   d1, d2, d3;
    bool    has_neg, has_pos;

    std::cout << a.getX().toFloat() << a.getY().toFloat() << std::endl;
	std::cout << b.getX().toFloat() << b.getY().toFloat() << std::endl;
	std::cout << c.getX().toFloat() << c.getY().toFloat() << std::endl;
	std::cout << point.getX().toFloat() << point.getY().toFloat() << std::endl;


    d1 = sign(point, a, b); 
    d2 = sign(point, b, c);
    d3 = sign(point, a, c);

    has_neg = d1 < 0 || d2 < 0 || d3 < 0;
    has_pos = d1 > 0 || d2 > 0 || d3 > 0;

    return (!(has_neg && has_pos));
}
