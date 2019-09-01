// Target-Heart-Rate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "utils.h"
#include <assert.h>
#include "HeartRates.h"

int main()
{
	assert(isLeapYear(172800));
	assert(!isLeapYear(86400));
	assert(!isLeapYear(2019));
	assert(isLeapYear(2020));
	assert(isLeapYear(2004));
	assert(isLeapYear(2000));
    std::cout << "Hello World!\n";

	std::string firstName = "Lei";
	std::string lastName = "Li";

	HeartRates myHearRates(firstName, lastName, 11, 11, 1111);

	std::cout << myHearRates.getFirstName() << " " << myHearRates.getLastName() << ", " << myHearRates.getMonth() << "/" << myHearRates.getDay()
		<< "/" << myHearRates.getYear() << ", " << myHearRates.getAge() << " years old" << ". Maximum heartRate: " << myHearRates.getMaximumHeartRate()
		<< ", target heartRates: " << myHearRates.getTargetHearRate() << std::endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
