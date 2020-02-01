#pragma once
#include <string>
#include "Time.h"

class Location
{
public:
	double North;
	double South;
};

class Emergency
{
private:
	std::string reporterName;
	std::string reporterPhoneNumber;
	Location emergencylocation;
	Time reportTime;
	std::string nature;
	std::string responseType;
	std::string responseStatus;
};

