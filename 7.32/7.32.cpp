// 7.32.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <array>

template< class T>
T recursiveMinimum(T* array, int startIndex, int endIndex);

int main()
{
	int a[5] = { 1, 3, -2, 1, -1 };
	std::cout << recursiveMinimum(a, 0, 4);
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
template< class T>
T recursiveMinimum(T * array, int startIndex, int endIndex)
{
	if (startIndex == endIndex - 1)
	{
		if (array[startIndex] < array[endIndex])
		{
			return array[startIndex];
		}
		else
		{
			return array[endIndex];
		}
	}
	else
	{
		T temp = recursiveMinimum(array, startIndex + 1, endIndex);
		if (array[startIndex] < temp)
		{
			return array[startIndex];
		}
		else
		{
			return temp;
		}
	}
}
