// 7.24.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Unfinished...

#include "pch.h"
#include <iostream>
#include <array>

bool willTwoQueenHavePeace(int i1, int j1, int i2, int j2);
void fillHeuristicArray(std::array< std::array<int, 8>, 8> &heuristicArray)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int rowAndColumnKilled = 8 + 8 - 1;
			int ascendingDiagonalKilled = 0;
			int k, l;
			for (k = i, l = j; k > 0 && l < 7; k--, l++)
			{
				ascendingDiagonalKilled++;
			}
			for (k = i, l = j; k < 7 && l > 0; k++, l--)
			{
				ascendingDiagonalKilled++;
			}
			int descendingDiagonalKilled = 0;
			for (k = i, l = j; k < 7 && l < 7; k++, l++)
			{
				descendingDiagonalKilled++;
			}
			for (k = i, l = j; k > 0 && l > 0; k--, l--)
			{
				descendingDiagonalKilled++;
			}
			heuristicArray[i][j] = rowAndColumnKilled + ascendingDiagonalKilled + descendingDiagonalKilled;
		}
	}

	for (auto row : heuristicArray)
	{
		for (auto v : row)
		{
			std::cout << v << " ";
		}
		std::cout << "\n";
	}
}

int main()
{
	std::array< std::array<int, 8>, 8> heuristicArray;
	
	fillHeuristicArray(heuristicArray);

	std::array< std::array<int, 8>, 8> occupiedArray = { 0 };

	int initRow = 0;
	int initColumn = 0;

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

bool willTwoQueenHavePeace(int i1, int j1, int i2, int j2)
{
	if (abs(i1 - i2) == abs(j1 - j2))
	{
		return false;
	}

	if (i1 == i2 || j1 == j2)
	{
		return false;
	}

	return true;
}
