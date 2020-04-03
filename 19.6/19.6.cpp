// 19.6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "List.h"
#include <iostream>

template <class T>
bool concatenate(List<T>& a, List<T>& b)
{
    for (size_t i = 0; i < b.size(); ++i)
    {
        if (!a.insertAtBack(b[i]))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    List<char> list1;
    List<char> list2;
    List<char> list3;
    List<char> list4;

    list1.insertAtBack('M');
    list1.insertAtBack('a');
    list1.insertAtBack('k');
    list1.insertAtBack('e');
    std::cout << list1;

    list2.insertAtBack(' ');
    list2.insertAtBack('L');
    list2.insertAtBack('o');
    list2.insertAtBack('v');
    list2.insertAtBack('e');
    std::cout << list2;

    list3.insertAtBack(' ');
    list3.insertAtBack('N');
    list3.insertAtBack('o');
    list3.insertAtBack('t');
    std::cout << list3;

    list4.insertAtBack(' ');
    list4.insertAtBack('W');
    list4.insertAtBack('a');
    list4.insertAtBack('r');
    std::cout << list4;

    if (!concatenate(list1, list2))
    {
        std::cerr << "concatenation failed\n";
    }
    else
    {
        list1.printStr();
    }

    if (!concatenate(list1, list3))
    {
        std::cerr << "concatenation failed\n";
    }
    else
    {
        list1.printStr();
    }

    if (!concatenate(list1, list4))
    {
        std::cerr << "concatenation failed\n";
    }
    else
    {
        list1.printStr();
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
