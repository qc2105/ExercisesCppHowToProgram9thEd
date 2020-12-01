// 16.8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>

const int SIZE = 20;

int main()
{
    std::cout << "Input 20 integers that there're duplicate ones in them:\n";

    std::array<int, SIZE> integers;

    for (int i = 0; i < 20; i++)
    {
        std::cin >> integers[i];
    }

    auto result = std::unique(integers.begin(), integers.end());

    std::ostream_iterator<int> out(std::cout, " ");

    std::copy(integers.begin(), result, out);

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
