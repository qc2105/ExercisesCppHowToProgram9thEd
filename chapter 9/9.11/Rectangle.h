#pragma once
class Rectangle
{
public:
	explicit Rectangle(double width = 1.0, double length = 1.0);

	Rectangle &setLength(double length);
	Rectangle &setWidth(double width);

	double getLength(void) const;
	double getWidth(void) const;

	double perimeter(void) const;
	double area(void) const;

private:
	double checkInput(double input) const;

	double length;
	double width;
};

