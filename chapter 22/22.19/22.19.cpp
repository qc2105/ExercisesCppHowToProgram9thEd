// 22.19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>

const int MAXSIZE = 256;

int countInLine(char* line, char targetChar);

int main()
{
    std::vector<char*> cStringVector;
    int count = 0;

    std::cout << "Input lines, Ctr+Z to stop:\n";

    char* str = new char[MAXSIZE];

    memset((void*)str, '\0', MAXSIZE);
    while (std::cin.getline(str, MAXSIZE))
    {
        cStringVector.push_back(str);

        str = new char[MAXSIZE];
        memset((void*)str, '\0', MAXSIZE);
    }

    std::cout << "Input target char:\n";
    std::cin.clear();

    char targetChar = '\0';
    std::cin >> targetChar;

    for (auto& v : cStringVector)
    {
        count += countInLine(v, targetChar);
        delete[] v;
    }

    std::cout << count << " occurences.\n";

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

int countInLine(char* line, char targetChar)
{
    char* searchPtr = nullptr;
    searchPtr = strchr(line, targetChar);
    int count = 0;

    while (searchPtr)
    {
        ++count;
        std::cout << searchPtr << std::endl;
        if (1 < strlen(searchPtr))
        {
            searchPtr = strchr(searchPtr + 1, targetChar);
        }
        else
        {
            break;
        }
    }

    return count;
}
