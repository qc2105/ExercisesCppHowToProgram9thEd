#include "InputProcessor.h"
#include <iostream>

name10_11::InputProcessor::InputProcessor(const std::string & _inputString, char _wordDelimiter, char _sentenceDelimiter)
	:userInputString(_inputString),
	wordDelimiter(_wordDelimiter),
	sentenceDelimiter(_sentenceDelimiter)
{
}

name10_11::InputProcessor::InputProcessor(char _wordDelimiter, char _sentenceDelimiter)
	:wordDelimiter(_wordDelimiter),
	sentenceDelimiter(_sentenceDelimiter)
{
	fetchUserInput();
}

void name10_11::InputProcessor::getTerms(std::vector<Term>& outputTerms) const
{
	std::vector<std::string> sentences, words;
	getSentences(sentences);

	for (size_t i = 0; i < sentences.size(); i++)
	{
		getWords(sentences.at(i), words);
		Term tempTerm;
		tempTerm.setCoefficeint(std::stod(words.at(0)));
		tempTerm.setExponent(static_cast<unsigned>(std::stoul(words.at(1))));
		outputTerms.push_back(tempTerm);
	}
}

void name10_11::InputProcessor::fetchUserInput(void)
{
	std::cout << "Please input like this: <coefficient>,<exponent>;..; for example: 1.3,3;2.4,2;5,1;" << std::endl;
	std::cin >> userInputString;
}

void name10_11::InputProcessor::getSentences(std::vector<std::string> &outputSentences) const
{
	outputSentences = getStringTokens(userInputString, sentenceDelimiter);
}

void name10_11::InputProcessor::getWords(const std::string & inputSentence, std::vector<std::string>& outputWords) const
{
	outputWords = getStringTokens(inputSentence, wordDelimiter);
}

std::vector<std::string> name10_11::InputProcessor::getStringTokens(const std::string &stringToBeProcessed, const char delimiter) const
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
