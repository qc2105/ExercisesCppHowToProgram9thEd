// 21.11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

void fillBodyPart(int i)
{
	switch (i)
	{
	case 1:
		std::cout << " 0 \n";
		break;
	case 2:
		std::cout << " 0 \n/  \n";
		break;
	case 3:
		std::cout << " 0 \n/| \n";
		break;
	case 4:
		std::cout << " 0 \n/|\\\n";
		break;
	case 5:
		std::cout << " 0 \n/|\\\n | \n";
		break;
	case 6:
		std::cout << " 0 \n/|\\\n | \n/\n";
		break;
	case 7:
		std::cout << " 0 \n/|\\\n | \n/ \\";
		break;
	default:
		break;
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	std::vector<std::string> targetWords = { "Blanks", "Global", "Vector" };

reBorn:

	int nCorrect = 0;
	int nIncorrect = 0;

	int randomIndex = rand() % 3;
	std::string targetWord = targetWords.at(randomIndex);

	std::cout << "Guess the word:\tXXXXXX\n";

	std::string guesses;
	while (nCorrect != 6)
	{
		char guess;
		std::cin >> guess;
		guesses += guess;
		if (guess != targetWord.at(0))
		{
			std::cout << "no\n";
			fillBodyPart(++nIncorrect);
		}
		else
		{
			std::cout << "yes\n";
			++nCorrect;
			targetWord.erase(targetWord.begin());
		}
		if (nIncorrect == 7)
		{
			std::cout << "\nYou are hanged!\n";
			exit(EXIT_SUCCESS);
		}
		std::cout << "Your guesses so far: " << guesses << std::endl;
	}

	std::cout << "Gongratulations!!! You guessed my word. Play again? yes/no\n";
	std::string answer;
	std::cin >> answer;
	if (answer == "yes")
	{
		goto reBorn;
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
