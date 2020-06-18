// 22.35.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

int main()
{
    char inputStr[15] = { '\0' };
    char* nextToken = nullptr;

    std::cout << "Input a phone number in the form: (555) 555-5555\n";

    std::cin.getline(inputStr, 15);

    char* tokenPtr = strtok_s(inputStr, " ", &nextToken);

    char areaCode[4] = { '\0' };

    for (int i = 0, j = 1; i < 3 && j < 5; ++i, ++j)
    {
        areaCode[i] = tokenPtr[j];
    }
    std::cout << areaCode;

    tokenPtr = strtok_s(NULL, "-", &nextToken);

    char phoneNumber[8] = { '\0' };

    strcpy_s(phoneNumber, 8, tokenPtr);

    tokenPtr = strtok_s(NULL, " ", &nextToken);

    strcat_s(phoneNumber, 8, tokenPtr);

    std::cout << phoneNumber << std::endl;

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
