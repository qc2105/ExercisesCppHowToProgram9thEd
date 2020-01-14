// 9.17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Date.h"
#include <ctime>

int main()
{
    std::cout << "Hello World!\n"; 
	Date tdate(12, 31, 2019);

	tdate.printDDD_YYYY();
	tdate.printMM_DD_YY();
	tdate.printEn_US();

	Date tdate2("June 14, 1992");
	tdate2.printEn_US();

	Date tdate3("365 2020");
	tdate3.printEn_US();

	Date tdate4("1/14/2020");
	tdate4.printEn_US();

	Date tdate5(time(0));
	tdate5.printEn_US();

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
