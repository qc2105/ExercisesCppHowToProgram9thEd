// 22.36.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

int main()
{
    std::string inputLine;

    std::cout << "Please input a line of text:\n";

    std::getline(std::cin, inputLine);

    char* nextToken = nullptr;
    char* tokenPtr = nullptr;
    char* inputCStr = new char[inputLine.length()+1];
    memset((void*)inputCStr, '\0', inputLine.length() + 1);
    strcpy_s(inputCStr, inputLine.length()+1, inputLine.c_str());

    tokenPtr = strtok_s(inputCStr, " ", &nextToken);
    std::vector<char*> words;
    char* newStr = new char[strlen(tokenPtr) + 1];
    strcpy_s(newStr, strlen(tokenPtr) + 1, tokenPtr);
    words.push_back(newStr);

    while ((tokenPtr = strtok_s(nullptr, " ", &nextToken)) != nullptr)
    {
        char* newStr = new char[strlen(tokenPtr) + 1];
        strcpy_s(newStr, strlen(tokenPtr)+1, tokenPtr);
        words.push_back(newStr);
    }

    for (auto it = words.rbegin(); it != words.rend(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    
    delete[] inputCStr;
    for (auto p : words)
    {
        delete[] p;
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
