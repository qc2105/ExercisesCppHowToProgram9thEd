#pragma once
#include <string>
#include <vector>

namespace name9_27 {
	class InputProcessor
	{
	public:
		explicit InputProcessor(const std::string& inputString, char _wordDelimiter = ',', char _sentenceDelimiter = ';');
		InputProcessor(char _wordDelimiter = ',', char _sentenceDelimiter = ';');

		void getInts(std::vector<std::vector<size_t> >& outputInts) const; // convert all the words into integers.

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
