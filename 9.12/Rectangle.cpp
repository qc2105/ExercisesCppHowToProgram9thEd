#include "Rectangle.h"
#include <cmath>

const double TOLERANCE = 0.0001;

Rectangle::Rectangle(Point _leftTop, Point _leftBottom, Point _rightTop, Point _rightBottom)
{
	set(_leftTop, _leftBottom, _rightTop, _rightBottom);
}

Rectangle & Rectangle::set(Point leftTop, Point leftBottom, Point rightTop, Point rightBottom)
{
	// TODO: insert return statement here
	if (!isPointInRec(leftTop, Point(0, 20), Point(20, 0)) ||
		!isPointInRec(leftBottom, Point(0, 20), Point(20, 0)) ||
		!isPointInRec(rightTop, Point(0, 20), Point(20, 0)) ||
		!isPointInRec(rightBottom, Point(0, 20), Point(20, 0)))
	{
		throw "Not in rec[(0,20), (20,0)\n";
	}

	if (::fabs(leftTop.x - leftBottom.x) > TOLERANCE ||
		::fabs(rightBottom.x - rightTop.x) > TOLERANCE ||
		::fabs(leftTop.y - rightTop.y) > TOLERANCE ||
		::fabs(rightBottom.y - leftBottom.y) > TOLERANCE)
	{
		throw "Not a Rectangle\n";
	}

	this->leftTop = leftTop;
	this->leftBottom = leftBottom;
	this->rightTop = rightTop;
	this->rightBottom = rightBottom;

	return *this;
}

double Rectangle::area(void) const
{
	double horizontalLength = ::fabs(rightTop.x - leftTop.x);
	double verticalLength = ::fabs(leftBottom.y - leftTop.y);

	return horizontalLength * verticalLength;
}

bool Rectangle::isPointInRec(Point testObject, Point recTopLeft, Point recRightBottom) const
{
	if (testObject.x > recTopLeft.x && 
		testObject.x < recRightBottom.x &&
		testObject.y > recRightBottom.y && 
		testObject.y < recTopLeft.y)
	{
		return true;
	}
	
	return false;
}

double Rectangle::premeter(void) const
{
	double horizontalLength = ::fabs(rightTop.x - leftTop.x);
	double verticalLength = ::fabs(leftBottom.y - leftTop.y);

	return (horizontalLength + verticalLength) * 2;
}

double Rectangle::length(void) const
{
	double horizontalLength = ::fabs(rightTop.x - leftTop.x);
	double verticalLength = ::fabs(leftBottom.y - leftTop.y);

	return (horizontalLength > verticalLength) ? horizontalLength : verticalLength;
}

double Rectangle::width(void) const
{
	double horizontalLength = ::fabs(rightTop.x - leftTop.x);
	double verticalLength = ::fabs(leftBottom.y - leftTop.y);

	return (horizontalLength < verticalLength) ? horizontalLength : verticalLength;
}

bool Rectangle::isSquare(void) const
{
	if (::fabs(length() - width()) < TOLERANCE)
	{
		return true;
	}
	else
	{
		return false;
	}
}
