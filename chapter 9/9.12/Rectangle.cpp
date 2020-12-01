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

	if (::fabs(::pow(leftTop.distance(leftBottom), 2) + ::pow(leftBottom.distance(rightBottom), 2) - ::pow(leftTop.distance(rightBottom), 2) ) >= TOLERANCE ||
		::fabs(::pow(leftTop.distance(rightTop), 2) + ::pow(rightBottom.distance(rightTop), 2) - ::pow(leftTop.distance(rightBottom), 2) ) >= TOLERANCE)
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
	return width() * length();
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
	return (length() + width()) * 2;
}

double Rectangle::length(void) const
{
	return (leftTop.distance(leftBottom) > leftTop.distance(rightTop)) ? leftTop.distance(leftBottom) : leftTop.distance(rightTop);
}

double Rectangle::width(void) const
{
	return (leftTop.distance(leftBottom) < leftTop.distance(rightTop)) ? leftTop.distance(leftBottom) : leftTop.distance(rightTop);
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
