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
		throw "Not a rectangle\n";
	}

	if (leftTop.x >= rightTop.x ||
		leftTop.y <= leftBottom.y)
	{
		throw "Point leftTop.x must be less than rightTop.x && leftTop.y must be bigger than leftBottom.y\n";
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

Point Rectangle::center(void) const
{
	double k1 = (rightBottom.y - leftTop.y) / (rightBottom.x - leftTop.x);
	double k2 = (rightTop.y - leftBottom.y) / (rightTop.x - leftBottom.x);
	double b1 = rightBottom.y - k1 * rightBottom.x;
	double b2 = rightTop.y - k2 * rightTop.x;

	return Point((b1 - b2) / (k2 - k1), k1*(b1 - b2) / (k2 - k1) + b1);
}

Rectangle & Rectangle::move(Point newCenter)
{
	// TODO: insert return statement here
	moveWithOutCheck(newCenter);

	this->set(leftTop, leftBottom, rightTop, rightBottom);

	return *this;
}

Rectangle & Rectangle::moveWithOutCheck(Point newCenter)
{
	// TODO: insert return statement here
	double deltaX = newCenter.x - center().x;
	double deltaY = newCenter.y - center().y;
		
	leftTop.x += deltaX;
	leftTop.y += deltaY;
	leftBottom.x += deltaX;
	leftBottom.y += deltaY;

	rightTop.x += deltaX;
	rightTop.y += deltaY;
	rightBottom.x += deltaX;
	rightBottom.y += deltaY;

	return *this;
}

Rectangle & Rectangle::moveByVec(vec2d _vec)
{
	// TODO: insert return statement here
	Point newCenter;
	newCenter.x = center().x + _vec.x;
	newCenter.y = center().y + _vec.y;

	return move(newCenter);
}

Rectangle & Rectangle::rotate(double theta)
{
	// TODO: insert return statement here
	Point oldCenter = center();

	this->moveWithOutCheck(Point(0, 0));
	Point newLeftTop, newLeftBottom, newRightTop, newRightBottom;
	
	newLeftTop.x = leftTop.x * ::cos(theta) - leftTop.y * ::sin(theta);
	newLeftTop.y = leftTop.x * ::sin(theta) + leftTop.y * ::cos(theta);
	
	newLeftBottom.x = leftBottom.x * ::cos(theta) - leftBottom.y * ::sin(theta);
	newLeftBottom.y = leftBottom.x * ::sin(theta) + leftBottom.y * ::cos(theta);

	newRightTop.x = rightTop.x * ::cos(theta) - rightTop.y * ::sin(theta);
	newRightTop.y = rightTop.x * ::sin(theta) + rightTop.y * ::cos(theta);

	newRightBottom.x = rightBottom.x * ::cos(theta) - rightBottom.y * ::sin(theta);
	newRightBottom.y = rightBottom.x * ::sin(theta) + rightBottom.y * ::cos(theta);
	
	leftTop = newLeftTop;
	leftBottom = newLeftBottom;
	rightTop = newRightTop;
	rightBottom = newRightBottom;

	this->move(oldCenter);

	return *this;
}

Rectangle & Rectangle::scale(double ratio)
{
	// TODO: insert return statement here
	Point newLeftTop, newLeftBottom, newRightTop, newRightBottom;

	newLeftTop.x = leftTop.x * ratio ;
	newLeftTop.y = leftTop.y * ratio;

	newLeftBottom.x = leftBottom.x * ratio ;
	newLeftBottom.y = leftBottom.y * ratio;

	newRightTop.x = rightTop.x * ratio;
	newRightTop.y = rightTop.y * ratio;

	newRightBottom.x = rightBottom.x * ratio;
	newRightBottom.y = rightBottom.y * ratio;

	Point cen = center();

	this->set(newLeftTop, newLeftBottom, newRightTop, newRightBottom);

	this->move(cen);

	return *this;
}

void Rectangle::draw(void)
{
	std::vector<Point> leftSidePoints, rightSidePoints;
	line(leftSidePoints, leftTop, leftBottom, perimeterCharacter);
	line(leftBottom, rightBottom, perimeterCharacter);
	line(rightSidePoints, rightTop, rightBottom, perimeterCharacter);
	line(rightTop, leftTop, perimeterCharacter);

	for (size_t i = 1; i < rightSidePoints.size() - 1; i++)
	{
		line(Point(leftSidePoints.at(i).x + 1, leftSidePoints.at(i).y), Point(rightSidePoints.at(i).x - 1, rightSidePoints.at(i).y), fillCharacter);
	}
		
	for (auto row : screen)
	{
		for (auto v : row)
		{
			std::cout << v;
		}
		std::cout << std::endl;
	}

	return;
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

void Rectangle::line(Point start, Point end, char c)
{
	std::vector<Point> temp;
	line(temp, start, end, c);
}

void Rectangle::line(std::vector<Point>& linePoints, Point start, Point end, char c)
{
	if (start.x > end.x)
	{
		Point temp = start;
		start = end;
		end = temp;
	}
	if (::fabs(start.x - end.x) < TOLERANCE)
	{
		if (start.y > end.y)
		{
			Point temp = start;
			start = end;
			end = temp;
		}

		for (int i = (int)start.y; i <= (int)end.y; i++)
		{
			screen.at((int)start.x).at(i) = c;
			linePoints.push_back(Point((int)start.x, i));
		}
		return;
	}
	else if (::fabs(start.y - end.y) < TOLERANCE)
	{
		for (int i = (int)start.x; i <= (int)end.x; i++)
		{
			screen.at(i).at((int)start.y) = c;
			linePoints.push_back(Point(i, (int)start.y));
		}
		return;
	}
	else
	{
		for (int i = (int)start.x; i <= (int)end.x; i++)
		{
			double k = (end.y - start.y) / (end.x - start.x);
			double b = end.y - k * end.x;
			int y = static_cast<int>(k * i + b);
			screen.at(i).at(y) = c;
			linePoints.push_back(Point(i, y));
		}
		return;
	}
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
