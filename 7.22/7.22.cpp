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
	std::array< std::array<int, 8>, 8> mChessBoard;
	std::array< std::array<int, 8>, 8> accessibility;

	int mCurrentRow = 0;
	int mCurrentColumn = 0;

	KnightTour(int size = 64, int initialRow = 0, int initialColumn = 0);
	void initialize(int initialRow = 0, int initialColumn = 0);

	void move(int moveType);

	bool isMoveValid(int moveType);

	void showChessBoard();

	bool isTheEnd();

	// Get next move heuristicly according to the accessibility metrix.
	int nextMoveType();

};

// This program is unfinished.
int main()
{
	KnightTour testRun;
	int nFullTour = 0;

	for (int initialRow = 0; initialRow < 8; initialRow++)
	{
		for (int initialColumn = 0; initialColumn < 8; initialColumn++)
		{
			std::cout << "Initialized on location: [" << initialRow << ","
				<< initialColumn << "] ";
			testRun.initialize(initialRow, initialColumn);

			while (testRun.mCount <= 64)
			{
				int i = testRun.nextMoveType();
				testRun.move(i);

				if (testRun.isTheEnd())
				{
					break;
				}
			}
			std::cout << testRun.mCount << '\n';
			testRun.showChessBoard();
			if (testRun.mCount == 63)
			{
				nFullTour++;
			}
		}
	}

	std::cout << "Got " << nFullTour << " full tours\n";

	return 0;
}


KnightTour::KnightTour(int size, int initializeRow, int initializeColumn)
	:mSize(size),
	mCount(0),
	accessibility({0}),
	mChessBoard({0})
{
	initialize(initializeRow, initializeColumn);
}

void KnightTour::initialize(int initialRow, int initialColumn)
{
	mCount = 0;
	mChessBoard = { 0 };
	accessibility = std::array< std::array<int, 8>, 8> {
			2, 3, 4, 4, 4, 4, 3, 2,
			3, 4, 6, 6, 6, 6, 4, 3,
			4, 6, 8, 8, 8, 8, 6, 4,
			4, 6, 8, 8, 8, 8, 6, 4,
			4, 6, 8, 8, 8, 8, 6, 4,
			4, 6, 8, 8, 8, 8, 6, 4,
			3, 4, 6, 6, 6, 6, 4, 3,
			2, 3, 4, 4, 4, 4, 3, 2
	}; 

	mCurrentRow = initialRow;
	mCurrentColumn = initialColumn;

	mChessBoard[mCurrentRow][mCurrentColumn] = 1;
	for (int i = 0; i < 8; i++)
	{
		if (isMoveValid(i))
		{
			int row = mArrayVertical[i] + mCurrentRow;
			int column = mArrayHorrizontal[i] + mCurrentColumn;
			accessibility[row][column]--;
		}
	}
}

void KnightTour::move(int moveType)
{
	accessibility[mCurrentRow][mCurrentColumn]--;
	mCurrentRow += mArrayVertical[moveType];
	mCurrentColumn += mArrayHorrizontal[moveType];
	mChessBoard[mCurrentRow][mCurrentColumn] = 1;

	for (int i = 0; i < 8; i++)
	{
		if (isMoveValid(i))
		{
			int row = mArrayVertical[i] + mCurrentRow;
			int column = mArrayHorrizontal[i] + mCurrentColumn;
			accessibility[row][column]--;
		}
	}

	//std::cout << " -> " << mCurrentRow  << ", " << mCurrentColumn << ", movement ";
	mCount++;
	//std::cout << mCount << '\n';
}

bool KnightTour::isMoveValid(int moveType)
{
	int row, column;
	if (moveType >= 0 && moveType < 8)
	{
		row = mArrayVertical[moveType] + mCurrentRow;
		column = mArrayHorrizontal[moveType] + mCurrentColumn;

		if (column > 7 || row > 7 || column < 0 || row < 0)
		{
			return false;
		}
		else if (mChessBoard[row][column] == 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}

	return false;
}

void KnightTour::showChessBoard()
{
	for (auto row : mChessBoard)
	{
		for (auto v : row)
		{
			if (v == 1)
			{
				std::cout << "*";
			}
			else
			{
				std::cout << "o";
			}
		}
		std::cout << '\n';
	}

	for (auto row : accessibility)
	{
		for (auto v : row)
		{
			std::cout << v;
		}
		std::cout << "\n";
	}
}

bool KnightTour::isTheEnd()
{
	int i, nInvalid;
	for (i = 0, nInvalid = 0; i < 8; i++)
	{
		if (!isMoveValid(i))
		{
			nInvalid++;
		}
	}

	if (nInvalid < 8)
	{
		return false;
	}
	return true;
}

int KnightTour::nextMoveType()
{
	int ret = 0;
	int mostInaccessible = 8;
	for (int i = 0; i < 8; i++)
	{
		if (isMoveValid(i))
		{
			int row = mCurrentRow + mArrayVertical[i];
			int column = mCurrentColumn + mArrayHorrizontal[i];
			int newInaccessible = accessibility[row][column];
			if (newInaccessible < mostInaccessible)
			{
				mostInaccessible = newInaccessible;
				ret = i;
			}
		}
	}

	return ret;
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
