// 21.13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <locale>
#include <iterator>

bool compareAnimalNames(const std::string& name1, const std::string& name2)
{
	std::string Upper1;
	std::string Upper2;

	std::locale loc;

	for (auto v : name1)
	{
		if (std::isupper(v, loc))
		{
			Upper1 += v;
		}
	}

	for (auto v : name2)
	{
		if (std::isupper(v, loc))
		{
			Upper2 += v;
		}
	}

	return Upper1 < Upper2;
}

int main()
{
	std::vector<std::string> animalNames = {"Cat", "Dog", "Tiger", "Eagle", "Hauk", "Lion", "Rabbit"};

	std::sort(animalNames.begin(), animalNames.end(), compareAnimalNames);

	std::ostream_iterator<std::string> out(std::cout, " ");

	std::copy(animalNames.begin(), animalNames.end(), out);

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
