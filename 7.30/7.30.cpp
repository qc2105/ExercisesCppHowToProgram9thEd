// 7.30.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

template <class T>
void printArray(T *array, int startIndic, int endIndic);

int main()
{
	double a[10];

	for (int i = 0; i < sizeof(a) / sizeof(double); i++)
	{
		a[i] = i * 0.3;
	}

	printArray(a, 0, 9);
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

template<class T>
void printArray(T *array, int startIndic, int endIndic)
{
	if (startIndic == endIndic)
	{
		std::cout << array[endIndic] << " ";
	}
	else
	{
		std::cout << array[startIndic] << " ";
		printArray(array, ++startIndic, endIndic);
	}
}
