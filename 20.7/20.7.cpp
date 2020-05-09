// 20.7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BucketSort.h"
#include <iterator>
#include <cstdlib>
#include <ctime>

int main()
{
    std::vector<size_t> items;

    srand(static_cast<unsigned int>(time(0)));
    int num = 0;
    for (size_t i = 0; i < 100; ++i)
    {
        num = rand() % 100 + 1;
        items.push_back(static_cast<size_t>(num));
    }

    BucketSort bucketSort;
    bucketSort(items);

    std::ostream_iterator<size_t> out(std::cout, " ");
    std::copy(items.begin(), items.end(), out);

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
