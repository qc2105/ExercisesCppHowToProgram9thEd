#pragma once
#include "Tree.h"
#include <string>
#include <sstream>

namespace name19_17
{
	template <class T = std::string>
	class WordTree : public Tree<std::string>
	{
	public:
		explicit WordTree(const std::string& sentence) :
			sentenceStringStream(sentence)
		{
			std::string word;
			while (sentenceStringStream >> word)
			{
				Tree<std::string>::insertNode(word);
			}
		}

		explicit WordTree(const char* sentence) :
			sentenceStringStream(sentence)
		{
			std::string word;
			while (sentenceStringStream >> word)
			{
				Tree<std::string>::insertNode(word);
			}
		}
	private:
		std::stringstream sentenceStringStream;
	};
}
