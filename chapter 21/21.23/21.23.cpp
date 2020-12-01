// 21.23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    std::string str = "abcdefghijklmnopqrstuvwxyz";

    for (size_t i = 0; i < 13; ++i)
    {
        std::cout << ' ';
    }
    std::cout << str.at(0) << std::endl;
    for (size_t i = 1; i < 14; ++i)
    {
        for (size_t j = 0; j < 13 - i; ++j)
        {
            std::cout << ' ';
        }
        std::string firstHalf = str.substr(i, i);
        std::cout << firstHalf;
        if (i != 13)
        {
            std::cout << str.at(i * 2);
        }
        else
        {
            std::cout << '{';
        }
        for (auto it = firstHalf.rbegin(); it != firstHalf.rend(); ++it)
        {
            std::cout << *it;
        }
        std::cout << std::endl;
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
