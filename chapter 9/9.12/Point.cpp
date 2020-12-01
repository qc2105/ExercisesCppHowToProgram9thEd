#include "Point.h"
#include <cmath>

Point::Point(double _x, double _y)
	:x(_x),
	y(_y)
{
}

double Point::distance(const Point & p) const
{
	return ::sqrt(::pow((this->x - p.x), 2) + ::pow((this->y - p.y), 2));
}