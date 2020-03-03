// 14.13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>

int main()
{
   	std::cout << std::left;
	std::cout << std::setw(24) << "TYPE" << std::setw(8) << "SIZEOF" << std::endl;
	std::cout << std::setw(24) << "char" << std::setw(8) << sizeof(char) << std::endl;
	std::cout << std::setw(24) << "unsigned char" << std::setw(8) << sizeof(unsigned char) << std::endl;
	std::cout << std::setw(24) << "short int" << std::setw(8) << sizeof(short int) << std::endl;
	std::cout << std::setw(24) << "unsigned short int" << std::setw(8) << sizeof(unsigned short int) << std::endl;
	std::cout << std::setw(24) << "int" << std::setw(8) << sizeof(int) << std::endl;
	std::cout << std::setw(24) << "unsigned int" << std::setw(8) << sizeof(unsigned int) << std::endl;
	std::cout << std::setw(24) << "long int" << std::setw(8) << sizeof(long int) << std::endl;
	std::cout << std::setw(24) << "unsigned long int" << std::setw(8) << sizeof(unsigned long int) << std::endl;
	std::cout << std::setw(24) << "float" << std::setw(8) << sizeof(float) << std::endl;
	std::cout << std::setw(24) << "double" << std::setw(8) << sizeof(double) << std::endl;
	std::cout << std::setw(24) << "long double" << std::setw(8) << sizeof(long double) << std::endl;

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
