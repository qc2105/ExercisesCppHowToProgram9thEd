// 15.25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../15.24/prime.h"
#include <iterator>

int main()
{
    std::set<size_t> primeFactors;
    std::vector<size_t> uniqueFactors;

    if (!getPrimesFactors(128, primeFactors) || !getUniquePrimesFactors(128, uniqueFactors))
    {
        exit(EXIT_FAILURE);
    }

    std::ostream_iterator<size_t> outFactors(std::cout, " ");
    std::copy(primeFactors.begin(), primeFactors.end(), outFactors);
    std::cout << '\n';

    std::ostream_iterator<size_t> outUniqueFactors(std::cout, " * ");
    
    std::cout << "128 = ";
    for (size_t i = 0; i < uniqueFactors.size(); ++i)
    {
        if (i != uniqueFactors.size() - 1)
        {
            std::cout << uniqueFactors.at(i) << " * ";
        }
        else
        {
            std::cout << uniqueFactors.at(i) << "\n";
        }
    }

    std::cout << '\n';

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
