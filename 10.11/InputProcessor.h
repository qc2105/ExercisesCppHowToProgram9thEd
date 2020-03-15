#pragma once
#include <string>
#include <vector>
#include "Polynomial.h"

namespace name10_11 {

	class InputProcessor
	{
	public:
		explicit InputProcessor(const std::string& inputString, char _wordDelimiter = ',', char _sentenceDelimiter = ';');
		InputProcessor(char _wordDelimiter = ',', char _sentenceDelimiter = ';');

		void getTerms(std::vector<Term>& outputTerms) const; // one word is corresponding to one term.

	private:
		void fetchUserInput(void);

		void getSentences(std::vector<std::string>& outputSentences) const; // from an input string, there're many sentences.
		void getWords(const std::string& inputSentence, std::vector<std::string>& outputWords) const; // from one sentence, there're many words. (two for now)

		std::vector<std::string> getStringTokens(const std::string& stringToBeProcessed, const char delimiter) const;

		std::string userInputString;
		char wordDelimiter;
		char sentenceDelimiter;
	};

};
