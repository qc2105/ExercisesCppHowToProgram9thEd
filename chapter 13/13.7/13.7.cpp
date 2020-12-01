// 13.7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

void formatPrint(int v);

int main()
{
	int decV = 10;
	int octV = 8;
	int hexV = 16;

	int value1, value2, value3;
	std::cin >> std::dec >> value1;
	std::cin >> std::oct >> value2;
	std::cin >> std::hex >> value3;

	formatPrint(value1);
	formatPrint(value2);
	formatPrint(value3);

	return 0;
}

void formatPrint(int v)
{
	std::cout << std::showbase;
	std::cout << std::dec << v << '\t' << std::oct << v << '\t' << std::hex << v << std::endl;
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
