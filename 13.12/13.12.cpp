// 13.12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

int main()
{
	std::cout << std::setw(10) << std::right << "F" << std::setw(10) << "C" << std::endl;
	for (int f = 0; f < 213; ++f)
	{
		double c = 5.0 / 9.0 * (f - 32);
		
		std::cout << std::fixed << std::right << std::setw(10) << std::noshowpos <<
			f << std::setw(10) << std::setprecision(3) << std::showpos << c << std::endl;
	}

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
