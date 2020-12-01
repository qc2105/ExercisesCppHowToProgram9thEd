// 20.6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include "List.h"
#include <cstdlib>
#include <ctime>
using namespace name20_6;

int main()
{
    List<int> list;
    List<int> list2;

    srand(time(0));
    int num = -1;
    for (size_t i = 0; i < 10; ++i)
    {
        num = rand() % 10;
        list.insertAtBack(num);
        list2.insertAtBack(num);
    }

    std::cout << list;
    list.mSort();
    std::cout << list;
    std::cout << "--------------------" << std::endl;
    std::cout << list2;
    list2.bSort();
    std::cout << list2;

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
