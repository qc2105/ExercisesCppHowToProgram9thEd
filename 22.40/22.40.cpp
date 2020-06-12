// 22.40.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstring>

// str must be null terminated, otherwise, the behaviors are undefined.
size_t strlen_arrayIndexVersion(const char * const str);
size_t strlen_pointersVersion(const char * const str);


int main()
{
    std::cout << "Input a string:\n";
    std::string inputString;
    std::getline(std::cin, inputString);

    std::cout << "Length by strlen from cstring: " << ::strlen(inputString.c_str()) << std::endl;
    std::cout << "Length by strlen_arrayIndexVersion: " << strlen_arrayIndexVersion(inputString.c_str()) << std::endl;
    std::cout << "Length by strlen_pointersVersion: " << strlen_pointersVersion(inputString.c_str()) << std::endl;

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

size_t strlen_arrayIndexVersion(const char* const str)
{
    size_t i = 0;

    for (; str[i] != '\0'; ++i)
    {
        ;
    }

    return i;
}

size_t strlen_pointersVersion(const char* const str)
{
    size_t i = 0;
    for (char* ptr = const_cast<char*>(str); *ptr != '\0'; ++i)
    {
        ++ptr;
    }
    return i;
}
