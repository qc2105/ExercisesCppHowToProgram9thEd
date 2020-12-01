#pragma once
class Point
{
public:
	explicit Point(double x = 0.0, double y = 0.0);

	double distance(const Point &p) const;

	double x;
	double y;
};

