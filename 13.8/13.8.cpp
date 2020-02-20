// 13.8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	char c = 'c';
	char *p = &c;

	std::cout << (int)p << '\n';
	std::cout << (long)p << '\n';
	std::cout << (unsigned)p << '\n';
	std::cout << (long long)p << '\n';
	std::cout << (short)p << '\n';
	std::cout << (unsigned long)p << '\n';
	std::cout << (char)p << '\n';
	std::cout << (unsigned long long)p << '\n';
	std::cout << static_cast<void *>(p) << '\n';

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
