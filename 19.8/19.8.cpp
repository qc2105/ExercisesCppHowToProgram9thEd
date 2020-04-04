// 19.8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.h"
#include <ctime>
#include <cstdlib>

using namespace name19_8;

int main()
{
    std::cout << "Hello World!\n";

    List<int> list;

    srand(static_cast<unsigned>(time(NULL)));

    for (size_t i = 0; i < 25; ++i)
    {
        list.insertAtBack(rand() % 101);
    }

    std::cout << list;

    size_t sum = 0;
    for (size_t i = 0; i < list.size(); ++i)
    {
        sum += list[i];
    }
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << static_cast<double>(sum) / list.size() << std::endl;

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
