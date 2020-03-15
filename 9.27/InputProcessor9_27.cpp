#include "InputProcessor.h"
#include <iostream>

name9_27::InputProcessor::InputProcessor(const std::string & _inputString, char _wordDelimiter, char _sentenceDelimiter)
	:userInputString(_inputString),
	wordDelimiter(_wordDelimiter),
	sentenceDelimiter(_sentenceDelimiter)
{
}

name9_27::InputProcessor::InputProcessor(char _wordDelimiter, char _sentenceDelimiter)
	:wordDelimiter(_wordDelimiter),
	sentenceDelimiter(_sentenceDelimiter)
{
	fetchUserInput();
}

void name9_27::InputProcessor::getInts(std::vector<std::vector<size_t> > &outputInts) const
{
	std::vector<std::string> sentences, words;
	getSentences(sentences);

	for (size_t i = 0; i < sentences.size(); i++)
	{
		getWords(sentences.at(i), words);
		std::vector<size_t> ints;
		for (size_t j = 0; j < words.size(); j++)
		{
			size_t tempInt = std::stoull(words.at(j));
			ints.push_back(tempInt);
		}
		outputInts.push_back(ints);
	}
}

void name9_27::InputProcessor::fetchUserInput(void)
{
	std::cout << "Please input the replacement commands like: 1,2;2,3;5,1;" << std::endl;
	std::cin >> userInputString;
}

void name9_27::InputProcessor::getSentences(std::vector<std::string> &outputSentences) const
{
	outputSentences = getStringTokens(userInputString, sentenceDelimiter);
}

void name9_27::InputProcessor::getWords(const std::string & inputSentence, std::vector<std::string>& outputWords) const
{
	outputWords = getStringTokens(inputSentence, wordDelimiter);
}

std::vector<std::string> name9_27::InputProcessor::getStringTokens(const std::string &stringToBeProcessed, const char delimiter) const
{
	std::string sentence, nextStringToProcess;
	std::vector<std::string> sentences;

	size_t delimiterPosition;

	for (delimiterPosition = 0, nextStringToProcess = stringToBeProcessed;
		delimiterPosition + 1 < stringToBeProcessed.size() && delimiterPosition != std::string::npos;
		nextStringToProcess = nextStringToProcess.substr(delimiterPosition + 1, stringToBeProcessed.size() - sentence.size() - 1))
	{
		delimiterPosition = nextStringToProcess.find(delimiter);
		sentence = nextStringToProcess.substr(0, delimiterPosition);
		if (!sentence.empty())
		{
			sentences.push_back(sentence);
		}
	}

	return sentences;
}
