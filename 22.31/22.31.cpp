// 22.31.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

const int MAXLINE = 256;

int main()
{
    char str1[256] = { '\0' };
    char str2[256] = { '\0' };

    std::cout << "Input two strings and the first number of characters to compare (must be less than 255 and bigger than 0):\n";

    std::cin.getline(str1, 255);
    std::cin.getline(str2, 255);
    size_t n = 0;
    std::cin >> n;
    str1[n] = '\0';
    str2[n] = '\0';

    if (strncmp(str1, str2, n) < 0)
    {
        std::cout << str1 << '\n' << "is less than\n" << str2 << '\n';
    }
    else if (strncmp(str1, str2, n) == 0)
    {
        std::cout << str1 << '\n' << "is equal \n" << str2 << '\n';
    }
    else if (strncmp(str1, str2, n) > 0)
    {
        std::cout << str1 << '\n' << "is greater than\n" << str2 << '\n';
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
