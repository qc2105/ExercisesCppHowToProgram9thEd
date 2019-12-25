#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle(double width, double length)
{
	setWidth(width);
	setLength(length);
}

Rectangle & Rectangle::setLength(double length)
{
	// TODO: insert return statement here
	this->length = checkInput(length);

	return *this;
}

Rectangle & Rectangle::setWidth(double width)
{
	// TODO: insert return statement here
	this->width = checkInput(width);

	return *this;
}

double Rectangle::getLength(void) const
{
	return length;
}

double Rectangle::getWidth(void) const
{
	return width;
}

double Rectangle::perimeter(void) const
{
	return (width + length) * 2;
}

double Rectangle::area(void) const
{
	return length * width;
}

double Rectangle::checkInput(double input) const
{
	if (input > 0.0 && input < 20.0)
	{
		return input;
	}
	else
	{
		throw "Invalid input, must be in range (0.0, 20.0)\n";
	}
}
