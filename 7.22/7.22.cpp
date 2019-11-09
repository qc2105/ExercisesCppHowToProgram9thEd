// 7.22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <array>
#include <cstdlib>

class KnightTour
{
public:

	int mSize;
	int mCount;

	std::array<int, 8> mArrayHorrizontal = { 2, 1, -1, -2, -2, -1, 1, 2 };
	std::array<int, 8> mArrayVertical = { -1, -2, -2, -1, 1, 2, 2, 1 };
	std::array< std::array<int, 8>, 8> mChessBoard = { 0 };

	int mCurrentRow = 3;
	int mCurrentColumn = 4;

	KnightTour(int size = 64);

	void move(int moveType);

};

// This program is unfinished.
int main()
{
	KnightTour testRun;

	while (testRun.mCount <= 64)
	{
		for (int i = 0; i < 8; i++)
		{
			testRun.move(i);
		}
	}

	std::cout << testRun.mCount << '\n';

	return 0;
}


KnightTour::KnightTour(int size)
	:mSize(size),
	mCount(0)
{
	
}

void KnightTour::move(int moveType)
{
	if (moveType >= 0 && moveType < 8)
	{
		mCurrentRow += mArrayVertical[moveType];
		mCurrentColumn += mArrayHorrizontal[moveType];

		if (mCurrentColumn > 7 || mCurrentRow > 7 || mCurrentColumn < 0 || mCurrentRow < 0)
		{
			mCurrentColumn -= mArrayHorrizontal[moveType];
			mCurrentRow -= mArrayVertical[moveType];
		}
		else if (mChessBoard[mCurrentRow][mCurrentColumn] == 1)
		{
			mCurrentColumn -= mArrayHorrizontal[moveType];
			mCurrentRow -= mArrayVertical[moveType];
		}
		else
		{
			mChessBoard[mCurrentRow][mCurrentColumn] = 1;
			std::cout << mCurrentRow << ", " << mCurrentColumn << " -> ";
			mCount++;
			std::cout << mCount << '\n';
		}
	}
	else
	{
		std::cout << "illeagal moveType: " << moveType << '\n';
	}
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
