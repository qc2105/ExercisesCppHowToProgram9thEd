#include "Rectangle.h"
#include <cmath>
#include <iostream>

const double TOLERANCE = 0.0001;

Rectangle::Rectangle(Point _leftTop, Point _leftBottom, Point _rightTop, Point _rightBottom)
	:fillCharacter('*'),
	perimeterCharacter('#')
{
	set(_leftTop, _leftBottom, _rightTop, _rightBottom);
	for (auto &row : screen)
	{
		for (auto &c : row)
		{
			c = ' ';
		}
	}
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

	if (::fabs(::pow(leftTop.distance(leftBottom), 2) + ::pow(leftBottom.distance(rightBottom), 2) - ::pow(leftTop.distance(rightBottom), 2)) >= TOLERANCE ||
		::fabs(::pow(leftTop.distance(rightTop), 2) + ::pow(rightBottom.distance(rightTop), 2) - ::pow(leftTop.distance(rightBottom), 2)) >= TOLERANCE)
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

void Rectangle::draw(void)
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (i >= (int)leftTop.x + 1 && i <= (int)rightTop.x - 1 &&
				j >= (int)leftBottom.y + 1 && j <= (int)leftTop.y - 1)
			{
				screen.at(i).at(j) = fillCharacter;
			}
		}
	}

	for (int i = (int)leftTop.x; i <= (int)rightTop.x; i++)
	{
		screen.at(i).at((int)leftTop.y) = perimeterCharacter;
		screen.at(i).at((int)leftBottom.y) = perimeterCharacter;
	}

	for (int j = (int)leftBottom.y; j <= (int)leftTop.y; j++)
	{
		screen.at((int)leftTop.x).at(j) = perimeterCharacter;
		screen.at((int)rightTop.x).at(j) = perimeterCharacter;
	}

	for (auto row : screen)
	{
		for (auto v : row)
		{
			std::cout << v;
		}
		std::cout << std::endl;
	}
}

void Rectangle::setFillCharacter(char c)
{
	fillCharacter = c;
}

void Rectangle::setPerimeterCharacter(char c)
{
	perimeterCharacter = c;
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
