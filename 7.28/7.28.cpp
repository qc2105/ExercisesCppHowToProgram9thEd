// 7.28.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <stdexcept>
#include <iostream>
#include <string>

bool isPalindrom(std::string const & str);
void showResult(std::string const &str);

int main()
{
	showResult("radar");
	showResult("able was i ere i saw elba");
	showResult("string");

	return 0;
}

bool isPalindrom(std::string const & str)
{
	switch (str.size())
	{
	case 0:
	case 1:
		return true;
		break;
	case 2:
		if (str[0] == str[1])
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 3:
		if (str[0] == str[2])
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	default:
		if (str[0] != str[str.size() - 1])
		{
			return false;
		}
		else
		{
			std::string tmpStr = str.substr(1, str.size() - 2);
			
			return isPalindrom(tmpStr);
		}
		break;
	}

	return false;
}

void showResult(std::string const & str)
{
	if (isPalindrom(str))
	{
		std::cout << str << ": true\n";
	}
	else
	{
		std::cout << str << ": false\n";
	}
}
