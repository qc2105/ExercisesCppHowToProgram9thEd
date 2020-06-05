// 22.14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>

int main()
{
    char s[100] = { '\0' };
    std::cout << "Input a string:\n";

    std::cin.getline(s, 99);

    for (int i = 0; s[i] != '\0'; ++i)
    {
        std::cout << static_cast<char>(::toupper(s[i]));
    }
    std::cout << std::endl;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        std::cout << static_cast<char>(::tolower(s[i]));
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
