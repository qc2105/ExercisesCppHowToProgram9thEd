#include "PhishingScanner.h"
#include <stdexcept>
#include <fstream>
#include <string>

PhishingScanner::PhishingScanner(const std::string& _signatureFilePath)
	:signatureFilePath(_signatureFilePath)
{
	if (!load())
	{
		throw "load error!\n";
	}
}

void PhishingScanner::reset(void)
{
	for (auto pair : occurrences)
	{
		pair.second = 0;
	}
}

double PhishingScanner::scanning(const std::string& emailFilePath)
{
	std::ifstream inf(emailFilePath, std::ios::in);
	if (!inf)
	{
		throw ("emailFileOpenError\n");
		return 0;
	}

	std::string wholeText;
	std::string line;
	while (!inf.eof())
	{
		std::getline(inf, line);
		for (auto& c : line)
		{
			unsigned char ch = static_cast<unsigned char>(c);
			if (isalpha(ch))
			{
				c = tolower(ch);
			}
		}
		wholeText += " " + line;
	}

	for (auto pair : occurrences)
	{
		size_t pos = 0;
		size_t p = 0;
		while ((p = wholeText.find(pair.first, pos)) != std::string::npos)
		{
			pos = p + 1;
			++occurrences.at(pair.first);
		}
	}

	double resultScore = 0;
	for (auto pair : pointValues)
	{
		resultScore += occurrences.at(pair.first) * pair.second;
	}

	return resultScore;
}

bool PhishingScanner::load(void)
{
	std::ifstream inf(signatureFilePath, std::ios::in);

	if (!inf)
	{
		return false;
	}

	std::string line;
	while (!inf.eof())
	{
		std::getline(inf, line);
		std::string signature;
		double pointValue = 0;
		size_t delimiterPos = line.find(";");
		if (delimiterPos == std::string::npos)
		{
			continue;
		}
		signature = line.substr(0, delimiterPos);
		for (auto& c : signature)
		{
			unsigned char ch = static_cast<unsigned char>(c);
			if (isalpha(ch))
			{
				c = tolower(ch);
			}
		}
		pointValue = std::stod(line.substr(delimiterPos + 1, line.size() - delimiterPos - 1));
		pointValues[signature] = pointValue;
		occurrences[signature] = 0;
	}

	return true;
}
