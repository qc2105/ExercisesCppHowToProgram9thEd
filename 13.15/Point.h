#pragma once
#include <iostream>

class Point
{
	// Input must be in these two forms (<int>,<int>) or <int>,<int>, no space is allowed
	friend std::istream & operator >> (std::istream &input, Point &point);
	friend std::ostream & operator << (std::ostream &output, const Point &point);
public:
	Point();
	Point(const int x, const int y);

private:
	int xCoordinate;
	int yCoordinate;
	bool inGoodSate;
	bool areDigits(const std::string s) const;
};


