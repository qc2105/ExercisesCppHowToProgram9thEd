// 9.10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Time.h"

void printSetError(Time::error_status es);

void printSetError(Time::error_status es)
{
	switch (es)
	{
	case Time::eOk:
		break;
	case Time::eInvalidHour:
		std::cout << "Invalid Hour\n";
		break;
	case Time::eInvalidMinute:
		std::cout << "Invalid Miniute\n";
		break;
	case Time::eInvalidSecond:
		std::cout << "Invalid Second\n";
		break;
	case Time::eInvalidTime:
		std::cout << "Invalid Time\n";
		break;
	default:
		std::cout << "Unkown Error\n";
		break;
	}
}

int main()
{
    std::cout << "Hello World!\n";
	Time t;
	Time::error_status es = t.setTime(33, 10, 10);
	printSetError(es);

	es = t.setHour(33);
	printSetError(es);
	
	es = t.setMinute(128);
	printSetError(es);

	es = t.setSecond(-5);
	printSetError(es);

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
