// 6.46.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// The reprint editon of the book by Publishing house of electronics industry has typos in exercise 6.46. The correct exercise is:
// (Math Library Functions) Write a program that tests as many of the math library functions
// in Fig. 6.2 as you can.Exercise each of these functions by having your program print out tables of
// return values for a diversity of argument values.

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <ctime>


int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    double x =1, y = 1;

    for (size_t i = 0; i < 10; ++i)
    {
        x = static_cast<double>(rand());
        y = static_cast<double>(rand());

        std::cout << std::setw(35) << "ceil(" + std::to_string(x) + "): " << std::setw(35) << ceil(x) << std::endl;
        std::cout << std::setw(35) << "cos(" + std::to_string(x) + "): " << std::setw(35) << cos(x) << std::endl;
        std::cout << std::setw(35) << "exp(" + std::to_string(x) + "): " << std::setw(35) << exp(x) << std::endl;
        std::cout << std::setw(35) << "fabs(" + std::to_string(x) + "): " << std::setw(35) << fabs(x) << std::endl;
        std::cout << std::setw(35) << "floor(" + std::to_string(x) + "): " << std::setw(35) << floor(x) << std::endl;
        std::cout << std::setw(35) << "fmod(" + std::to_string(x) + ", " + std::to_string(y) + "): " << std::setw(35) << fmod(x, y) << std::endl;
        std::cout << std::setw(35) << "log(" + std::to_string(x) + "): " << std::setw(35) << log(x) << std::endl;
        std::cout << std::setw(35) << "log10(" + std::to_string(x) + "): " << std::setw(35) << log10(x) << std::endl;
        std::cout << std::setw(35) << "pow(" + std::to_string(x) + ", " + std::to_string(y) + "): " << std::setw(35) << pow(x, y) << std::endl;
        std::cout << std::setw(35) << "sin(" + std::to_string(x) + "): " << std::setw(35) << sin(x) << std::endl;
        std::cout << std::setw(35) << "sqrt(" + std::to_string(x) + "): " << std::setw(35) << sqrt(x) << std::endl;
        std::cout << std::setw(35) << "tan(" + std::to_string(x) + "): " << std::setw(35) << tan(x) << std::endl;
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
