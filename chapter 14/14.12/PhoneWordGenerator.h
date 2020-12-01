#pragma once
#include <string>
#include <vector>
#include <iostream>

class PhoneWordGenerator
{
public:
	PhoneWordGenerator(const std::string &ofname = "results.txt");

	void getSevenDigits(std::istream &input);

	void outputResults(void) const;

private:
	std::string outputFileName;
	std::vector<char> InputDigits;
	std::vector<char> CVecForTwo;
	std::vector<char> CVecForThree;
	std::vector<char> CVecForFour;
	std::vector<char> CVecForFive;
	std::vector<char> CVecForSix;
	std::vector<char> CVecForSeven;
	std::vector<char> CVecForEight;
	std::vector<char> CVecForNine;
};

