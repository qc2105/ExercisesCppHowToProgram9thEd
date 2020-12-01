#pragma once
#include "Point.h"
#include <array>
#include <vector>

#define vec2d Point

class Rectangle
{
public:
	explicit Rectangle(Point leftTop, Point leftBottom, Point rightTop, Point rightBottom); //bugyy

	Rectangle& set(Point leftTop, Point leftBottom, Point rightTop, Point rightBottom); //buggy, we should not restrict the order of the points

	bool isSquare(void) const;

	double length(void) const;
	double width(void) const;
	double premeter(void) const;
	double area(void) const;
	Point center(void) const;
	Rectangle& move(Point newCenter);
	Rectangle& moveWithOutCheck(Point newCenter);
	Rectangle& moveByVec(vec2d _vec);
	Rectangle& rotate(double theta); //buggy
	Rectangle& scale(double ratio);
	
	void draw(void);
	void setFillCharacter(char c);
	void setPerimeterCharacter(char c);

private:
	bool isPointInRec(Point testObject, Point recTopLeft, Point recRightBottom) const;
	void line(Point start, Point end, char c);
	void line(std::vector<Point> &linePoints, Point start, Point end, char c);
	Point leftTop;
	Point leftBottom;
	Point rightTop;
	Point rightBottom;

	std::array< std::array<char, 25>, 25> screen;
	char fillCharacter;
	char perimeterCharacter;
};

