#pragma once
#include "Point.h"

class Rectangle
{
public:
	explicit Rectangle(Point leftTop, Point leftBottom, Point rightTop, Point rightBottom);

	Rectangle& set(Point leftTop, Point leftBottom, Point rightTop, Point rightBottom);

	bool isSquare(void) const;

	double length(void) const;
	double width(void) const;
	double premeter(void) const;
	double area(void) const;

private:
	bool isPointInRec(Point testObject, Point recTopLeft, Point recRightBottom) const;
	Point leftTop;
	Point leftBottom;
	Point rightTop;
	Point rightBottom;
};

