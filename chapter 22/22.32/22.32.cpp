// 22.32.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

int main()
{
    const char* article[] = {"the", "a", "one", "some", "any" };
    const char* noun[] = {"boy", "girl", "dog", "town", "car"};
    const char* verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    const char* preposition[] = { "to", "from", "over", "under", "on" };

    srand(static_cast<unsigned int>(time(0)));

    size_t sentenceMaxLength = 0;
    size_t maxLength = 0;
    
    for (auto w : article)
    {
        if (strlen(w) > maxLength)
        {
            maxLength = strlen(w);
        }
    }

    sentenceMaxLength += maxLength * 2;

    maxLength = 0;

    for (auto w : noun)
    {
        if (strlen(w) > maxLength)
        {
            maxLength = strlen(w);
        }
    }

    sentenceMaxLength += maxLength * 2;

    maxLength = 0;
    for (auto w : verb)
    {
        if (strlen(w) > maxLength)
        {
            maxLength = strlen(w);
        }
    }

    sentenceMaxLength += maxLength;

    maxLength = 0;
    for (auto v : preposition)
    {
        if (strlen(v) > maxLength)
        {
            maxLength = strlen(v);
        }
    }

    sentenceMaxLength += maxLength;

    
    for (int i = 0; i < 20; ++i)
    {
        char* sentence = new char[sentenceMaxLength + 5]; // 5: three spaces, one period, and a null terminal character.
        memset((void*)sentence, '\0', sentenceMaxLength + 5);

        int randNum = rand() % (sizeof(article) / sizeof(char*));
        strcpy_s(sentence, sentenceMaxLength + 5, article[randNum]);
        strcat_s(sentence, sentenceMaxLength + 5, " ");
        //strcat_s(sentence, sentenceMaxLength + 5, "\0");
        randNum = rand() % (sizeof(noun) / sizeof(char*));
        strcat_s(sentence, sentenceMaxLength + 5, noun[randNum]);
        strcat_s(sentence, sentenceMaxLength + 5, " ");
        randNum = rand() % (sizeof(verb) / sizeof(char*));
        strcat_s(sentence, sentenceMaxLength + 5, verb[randNum]);
        strcat_s(sentence, sentenceMaxLength + 5, " ");
        randNum = rand() % (sizeof(preposition) / sizeof(char*));
        strcat_s(sentence, sentenceMaxLength + 5, preposition[randNum]);
        strcat_s(sentence, sentenceMaxLength + 5, " ");
        randNum = rand() % (sizeof(article) / sizeof(char*));
        strcat_s(sentence, sentenceMaxLength + 5, article[randNum]);
        strcat_s(sentence, sentenceMaxLength + 5, " ");
        randNum = rand() % (sizeof(noun) / sizeof(char*));
        strcat_s(sentence, sentenceMaxLength + 5, noun[randNum]);
        strcat_s(sentence, sentenceMaxLength + 5, ".");
        sentence[0] = static_cast<char>(::toupper(static_cast<int>(sentence[0])));

        std::cout << sentence << " ";

        delete[] sentence;
    }
    
    std::cout << std::endl;

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

