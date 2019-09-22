// Chapter5-exercises-5.30.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

typedef struct quizStructure {
	std::string question;
	std::string answerA;
	std::string answerB;
	std::string answerC;
	std::string answerD;
	char correctAnswerId;
} quiz;

int main()
{
    std::cout << "Global Warming Facts Quiz\n"; 
	
	quiz globalWarmingQuizs[] = {
		{
			"How long will Emissions like carbon dioxide, nitrous oxide, and other greenhouses gases remain in the atmosphere?",
			"Serveral months",
			"Serveral days",
			"Serveral weeks",
			"Serveral decades",
			'D'
		},
		{
			"How sea levels will rise by the end of this century due to global warming?",
			"1~3 inches",
			"5~10 inches",
			"7~23 inches",
			"100~1000 inches",
			'C'
		},
		{
			"Where is one of the worst places to be affected by global warming.",
			"The Pacific Ocean",
			"The Atlantic Ocean",
			"The Indian Sea",
			"The Arctic",
			'D'
		},
		{
			"The Arctic ice is melting rapidly.When will the region be expected to have a completely ice-free summer?",
			"At least 2030",
			"At least 2040",
			"At least 2020",
			"At least 2050",
			'B'
		},
		{
			"How many species have become extinct due to disappearing habitats, ecosystems acidic oceans all caused due to global warming?",
			"Less than one thousand",
			"Less than one hundred",
			"More than one million",
			"Less than ten thousand",
			'C'
		}
	};

	unsigned int correctCount = 0;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "------" << "Quiz " << i << "------:\n";
		std::cout << globalWarmingQuizs[i].question << std::endl;
		std::cout << "\tA: " << globalWarmingQuizs[i].answerA << std::endl;
		std::cout << "\tB: " << globalWarmingQuizs[i].answerB << std::endl;
		std::cout << "\tC: " << globalWarmingQuizs[i].answerC << std::endl;
		std::cout << "\tD: " << globalWarmingQuizs[i].answerD << std::endl;
		std::cout << std::endl;

		std::cout << "Please input your answer, type in A B C or D and press the Enter key.\n";
		char answer;
		do {
			std::cin >> answer;
			answer = static_cast<char>(toupper(answer));
		} while (answer != 'A' && answer != 'B' && answer != 'C' && answer != 'D');
		
		if (answer == globalWarmingQuizs[i].correctAnswerId)
		{
			correctCount++;
		}
	}
	std::cout << std::endl;

	switch (correctCount)
	{
	case 5:
		std::cout << "Excellent!\n";
		break;
	case 4:
		std::cout << "Very good!\n";
		break;
	case 3:
	case 2:
	case 1:
	case 0:
	default:
		std::cout << "Time to brush up on your knowledge of global warming, you might want to read info on the following sites:\n"
			<< "https://www.conserve-energy-future.com/various-global-warming-facts.php\n"
			<< "https://www.ucsusa.org/global-warming/solutions/fight-misinformation/global-warming-skeptic.html\n";
		break;
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
