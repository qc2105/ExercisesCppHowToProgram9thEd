// 17.23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iterator>

int main()
{
    int nV = 5;
    double dV = 6.0;

    for (int i = 0; i < 2; ++i)
    {
        std::cout << "Input an integer less than 5 or bigger than 5:\n";

        int a = 0;

        std::istream_iterator<int> iIter(std::cin);

        a = *iIter;
        try
        {
            throw a < 5 ? nV : dV;
        }
        catch (const double& v)
        {
            std::cout << v << std::endl;
        }
        catch (const int& v)
        {
            std::cout << v << std::endl;
        }
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
