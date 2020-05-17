// 21.16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <iterator>

void getWords(const std::string& str, std::vector<std::string>& words);
bool isPalindromeWord(const std::string& word);

int main()
{
    std::string str = "Make Humans Great Again tommorrow noon!\n";

    std::cout << "Input a sentence: \n\tOr Ctr+Z on Windows to quit.\n";
    while (std::getline(std::cin, str))
    {
        std::vector<std::string> words;

        getWords(str, words);

        size_t nPalindromes = 0;
        for (const auto& v : words)
        {
            if (isPalindromeWord(v))
            {
                ++nPalindromes;
            }
        }

        std::cout << "Number of palindromes: " << nPalindromes << std::endl;
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

void getWords(const std::string& str, std::vector<std::string>& words)
{
    std::locale loc;
    std::string stringLeft = str;
    size_t spacePos;
    while ((spacePos = stringLeft.find(' ')) != std::string::npos)
    {
        std::string word = stringLeft.substr(0, spacePos + 1);
        std::string pureWord;
        for (size_t i = 0; i < word.size(); ++i)
        {
            if (isalpha(word.at(i), loc))
            {
                pureWord += word.at(i);
            }
        }
        
        words.push_back(pureWord);
        stringLeft = stringLeft.substr(spacePos + 1, str.size() - (spacePos + 1));
    }

    if (stringLeft.size() != 0)
    {
        std::string word = stringLeft;
        std::string pureWord;
        for (size_t i = 0; i < word.size(); ++i)
        {
            if (isalpha(word.at(i), loc))
            {
                pureWord += word.at(i);
            }
        }

        words.push_back(pureWord);
    }
}

bool isPalindromeWord(const std::string& word)
{
    std::string drow;

    for (auto it = word.rbegin(); it != word.rend(); ++it)
    {
        drow += *it;
    }

    return word == drow;
}

