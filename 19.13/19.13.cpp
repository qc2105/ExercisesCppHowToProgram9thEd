// 19.13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stack.h"
#include <string>

using namespace name19_13;

double evaluatePostfixExpress(std::string postfixStr);

int main()
{
    std::string infix = "6 2 + 5 * 8 4 / -";

    std::cout << evaluatePostfixExpress(infix) << std::endl;

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

double evaluatePostfixExpress(std::string postfixStr)
{
    Stack<double> stack;
    std::string operators = "-+%/*^";
    for (size_t i = 0; i < postfixStr.size(); ++i)
    {
        if (::isdigit(postfixStr.at(i)))
        {
            stack.push(static_cast<int>(postfixStr.at(i)) - static_cast<int>('0'));
        }
        else if (operators.find(postfixStr.at(i)) != std::string::npos)
        {
            double x = 0, y = 0;
            stack.pop(x);
            stack.pop(y);
            switch (postfixStr.at(i))
            {
            case '+':
                stack.push(y + x);
                break;
            case '-':
                stack.push(y - x);
                break;
            case '*':
                stack.push(y * x);
                break;
            case '/':
                stack.push(y / x);
                break;
            case '^':
                stack.push(::pow(y, x));
                break;
            case '%':
                stack.push(::fmod(y, x));
                break;
            default:
                throw std::invalid_argument("Unkown operator\n");
                break;
            }
        }
    }

    return stack.top();
}
