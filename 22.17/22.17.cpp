// 22.17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

const int MAXLINE = 256;

int main()
{
    char line[MAXLINE] = { '\0' };
    char targetString[MAXLINE] = { '\0' };

    std::cout << "Input a line of text:\n";

    std::cin.getline(line, 255);

    std::cout << "Input the target string:\n";

    std::cin.getline(targetString, 255);
    
    char* searchPtr = nullptr;
    searchPtr = strstr(line, targetString);

    while (searchPtr)
    {
        std::cout << searchPtr << std::endl;
        if (strlen(targetString) < strlen(searchPtr))
        {
            searchPtr = strstr(searchPtr + strlen(targetString), targetString);
        }
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
