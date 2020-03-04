#include "PhoneWordGenerator.h"
#include <fstream>
#include <string>

PhoneWordGenerator::PhoneWordGenerator(const std::string & ofname)
	:outputFileName(ofname),
	CVecForTwo({'A', 'B', 'C'}),
	CVecForThree({'D', 'E', 'F'}),
	CVecForFour({'G', 'H', 'I'}),
	CVecForFive({'J', 'K', 'L'}),
	CVecForSix({ 'M', 'N', 'O' }),
	CVecForSeven({'P', 'Q', 'R', 'S'}),
	CVecForEight({'T', 'U', 'V'}),
	CVecForNine({'W', 'X', 'Y', 'Z'})
{
}

void PhoneWordGenerator::getSevenDigits(std::istream & input)
{
	std::string inputString;
	bool valid = true;
	
	do  
	{
		std::cout << "Input the phone number in the format as: 686-2377, no 0 or 1 is allowed\n";
		input >> inputString;
		for (size_t i = 0; i < inputString.size(); ++i)
		{
			if (3 == i)
			{
				continue;
			}
			if (!isdigit(inputString.at(i)))
			{
				valid = false;
			}
		}
	} while (inputString.find('0') != std::string::npos ||
		inputString.find('1') != std::string::npos ||
		inputString.size() != 8 ||
		inputString.at(3) != '-' ||
		!valid);

	for (size_t i = 0; i < inputString.size(); ++i)
	{
		if (3 != i)
		{
			InputDigits.push_back(inputString.at(i));
		}
	}
}

void PhoneWordGenerator::outputResults(void) const
{
	std::vector<std::vector<char>> CharForDigits;
	for (size_t i = 0; i < InputDigits.size(); ++i)
	{
		switch (InputDigits.at(i))
		{
		case '2':
			CharForDigits.push_back(CVecForTwo);
			break;
		case '3':
			CharForDigits.push_back(CVecForThree);
			break;
		case '4':
			CharForDigits.push_back(CVecForFour);
			break;
		case '5':
			CharForDigits.push_back(CVecForFive);
			break;
		case '6':
			CharForDigits.push_back(CVecForSix);
			break;
		case '7':
			CharForDigits.push_back(CVecForSeven);
			break;
		case '8':
			CharForDigits.push_back(CVecForEight);
			break;
		case '9':
			CharForDigits.push_back(CVecForNine);
			break;
		default:
			break;
		}
	}

	std::fstream of(outputFileName, std::ios::out);
	if (!of)
	{
		std::cerr << "Output file creatation error\n";
		exit(EXIT_FAILURE);
	}

	for (size_t i0 = 0; i0 < CharForDigits.at(0).size(); ++i0)
	{
		for (size_t i1 = 0; i1 < CharForDigits.at(1).size(); ++i1)
		{
			for (size_t i2 = 0; i2 < CharForDigits.at(2).size(); ++i2)
			{
				for (size_t i3 = 0; i3 < CharForDigits.at(3).size(); ++i3)
				{
					for (size_t i4 = 0; i4 < CharForDigits.at(4).size(); ++i4)
					{
						for (size_t i5 = 0; i5 < CharForDigits.at(5).size(); ++i5)
						{
							for (size_t i6 = 0; i6 < CharForDigits.at(6).size(); ++i6)
							{
								of << CharForDigits.at(0).at(i0)
									<< CharForDigits.at(1).at(i1)
									<< CharForDigits.at(2).at(i2)
									<< CharForDigits.at(3).at(i3)
									<< CharForDigits.at(4).at(i4)
									<< CharForDigits.at(5).at(i5)
									<< CharForDigits.at(6).at(i6)
									<< std::endl;
							}
						}
					}
				}
			}
		}
	}

	of.close();

	std::cout << "Results are in: " << outputFileName << std::endl;
}
