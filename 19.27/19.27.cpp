// 19.27.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include "Queue.h"
#include "List.h"

using namespace name19_27;

int main()
{
    std::stringstream inputs("1 2 3 4 5 6 7");

    List<int> list;
    Queue<int> queue;

    inputs >> list;

    for (size_t i = 0; i < list.size(); ++i)
    {
        queue.enqueue(list[i]);
    }

    for (; queue.size() > 0; )
    {
        int v = -1;
        queue.dequeue(v);
        std::cout << v << ' ';
    }
    std::cout << std::endl;

    std::cout << list;

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
