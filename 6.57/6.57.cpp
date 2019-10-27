// 6.57.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

bool question(unsigned num1, unsigned num2, int type);

void newQuestion(unsigned& num1, unsigned& num2);
void newQuestion(unsigned& num1, unsigned& num2, int level);

int nLevel = 1;

int main()
{
	srand((unsigned int)time(0));
	unsigned num1 = 2, num2 = 8;
	unsigned nRight = 0;
	unsigned nTotal = 0;

	int type;

	std::cout << "Please enter a type of problems,\n 1 for addtion,\n 2 for subtraction,\n 3 for multiple,\n 4 for division,\n 5 for a mix of all:\n";
	std::string input;
	std::cin >> input;
	try
	{
		if (std::string("quit") == input)
		{
			exit(0);
		}
		type = std::stoi(input);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
		return false;
	};

	input = std::string("");
	std::cout << "Please enter a difficult level: \n";
	std::cin >> input;
	try
	{
		if (std::string("quit") == input)
		{
			exit(0);
		}
		nLevel = std::stoul(input);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
		return false;
	};

	bool randomOperation = false;
	if (5 == type)
	{
		randomOperation = true;
	}

	do
	{
		do
		{
			newQuestion(num1, num2, nLevel);
			if (randomOperation)
			{
				type = rand() % 4 + 1;
			}

			bool is_right;

			do
			{
				is_right = question(num1, num2, type);
				if (is_right)
				{
					nRight++;
				}
				nTotal += 1;
			} while (nTotal < 10 && !is_right);
			
		} while (nTotal < 10);

		double rightRatio = (double)nRight / (double)nTotal;
		if (rightRatio < 0.75)
		{
			std::cout << "Please ask your teacher for extra help.\n";
		}
		else
		{
			std::cout << "Congratulations, you are ready to go to the next level!\n";
		}

		nRight = 0;
		nTotal = 0;
	} while (true);

	return 0;
}

bool question(unsigned num1, unsigned num2, int type)
{
	switch (type)
	{
	case 1:
		std::cout << "How much is " << num1 << " add " << num2 << "?" << std::endl;
		break;
	case 2:
		std::cout << "How much is " << num1 << " subtract " << num2 << "?" << std::endl;
		break;
	case 3:
		std::cout << "How much is " << num1 << " multiply " << num2 << "?" << std::endl;
		break;
	case 4:
		std::cout << "How much is " << num1 << " divide " << num2 << "?" << std::endl;
		break;
	default:
		std::cout << "App Error! Call 999!" << std::endl;
		break;
	}
	
	double answer = 0;
	std::string input;
	std::cin >> input;
	try
	{
		if (std::string("quit") == input)
		{
			exit(0);
		}
		answer = std::stod(input);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
		return false;
	};

	int luckyNumber = rand() % 4 + 1;
	std::string commentsWhenRight = std::string("Very good!");
	std::string commentsWhenWrong = std::string("No. Please try again.");

	switch (luckyNumber)
	{
	case 1:
		// use the defaults
		break;
	case 2:
		commentsWhenRight = std::string("Excellent!");
		commentsWhenWrong = std::string("Wrong. Try once more.");
		break;
	case 3:
		commentsWhenRight = std::string("Nice work!");
		commentsWhenWrong = std::string("Don't give up!");
		break;
	case 4:
		commentsWhenRight = std::string("Keep up the good work!");
		commentsWhenWrong = std::string("No. Keep trying!");
		break;
	default:
		commentsWhenRight = std::string("Wow! You must be a genius to get here!");
		commentsWhenWrong = std::string("Crap! Dude! What have you done? The earth is flying no more.");
		break;
	}

	double expected = 0;

	switch (type)
	{
	case 1:
		expected = num1 + num2;
		break;
	case 2:
		expected = num1 - num2;
		break;
	case 3:
		expected = num1 * num2;
		break;
	case 4:
		expected = (double)num1 / (double)num2;
		break;
	default:
		expected = 0;
		break;
	}

	if (fabs(expected - answer) < 0.0001)
	{
		std::cout << commentsWhenRight << "\n";
		return true;
	}
	else
	{
		std::cout << commentsWhenWrong << "\n";
		return false;
	}

	return false;
}

void newQuestion(unsigned &num1, unsigned &num2)
{
	num1 = rand() % 9 + 1;
	num2 = rand() % 9 + 1;

	std::cout << "How much is " << num1 << " times " << num2 << "?" << std::endl;
}

void newQuestion(unsigned &num1, unsigned &num2, int level)
{
	unsigned temp = 9;

	std::string levelString;

	for (int i = 0; i < level; i++)
	{
		levelString.append(std::string("9"));
	}
	
	temp = std::stoul(levelString);

	if (levelString.size() > std::to_string(INT_MAX).size())
	{
		temp = INT_MAX;
	}

	num1 = rand() % temp + 1;
	num2 = rand() % temp + 1;
}
