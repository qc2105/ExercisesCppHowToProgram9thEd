// 19.9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include "List.h"

using namespace name19_9;

int main()
{
    std::cout << "Hello World!\n";

    std::stringstream ss("0 1 2 3 4 5 6 7 8 9");

    name19_9::List<char> list1;
    ss >> list1;
    list1.printStr();

    name19_9::List<char> list2;
    for (size_t i = 0; i < list1.size(); ++i)
    {
        list2.insertAtFront(list1[i]);
    }
    list2.printStr();

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
