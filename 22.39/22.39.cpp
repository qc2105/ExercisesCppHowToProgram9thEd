// 22.39.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "homeMadeStrUtils.h"

int main()
{
    const char* str1 = "helloWorld!!";
    const char* str2 = "helloWorld";

    std::cout << strcmp(str1, str2) << std::endl;
    std::cout << homeMadeStrcmpV1(str1, str2) << std::endl;
    std::cout << homeMadeStrcmpV2(str1, str2) << std::endl;

    for (size_t i = 0; i < strlen(str1); ++i)
    {
        std::cout << strncmp(str1, str2, i) << '\t';
        std::cout << homeMadeStrncmpV1(str1, str2, i) << '\t';
        std::cout << homeMadeStrncmpV2(str1, str2, i) << std::endl;
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

