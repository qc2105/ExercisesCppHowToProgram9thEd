// 19.14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stack.h"
#include <string>

using namespace name19_14;

// Pre-condition: each token is seperated by a space in postfixStr
// Post-condition: each token is an element in the tokens List, the order remains unchanged.
void tokenize(std::string postfixStr, List<std::string>& tokens);

bool areDigits(const std::string& token);

double evaluatePostfixExpress(List<std::string> postfixList);

int main()
{
    std::string infix = "60 2 + 5 * 100 4 / -";
    List<std::string> tokens;

    tokenize(infix, tokens);
    std::cout << "\"" << infix << "\"" << " was evaluated to: " << evaluatePostfixExpress(tokens) << std::endl;

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

void tokenize(std::string postfixStr, List<std::string>& tokens)
{
    std::string token;
    for (size_t i = 0; i < postfixStr.size(); ++i)
    {
        if (postfixStr.at(i) != ' ')
        {
            token.append(1, postfixStr.at(i));
        }
        else
        {
            tokens.insertAtBack(token);
            token.clear();
        }
    }
    if (!token.empty())
    {
        tokens.insertAtBack(token);
    }
}

bool areDigits(const std::string& token)
{
    for (auto& v : token)
    {
        if (!::isdigit(v))
        {
            return false;
        }
    }
    return true;
}

double evaluatePostfixExpress(List<std::string> postfixTokens)
{
    Stack<double> stack;
    std::string operators = "-+%/*^";
    for (size_t i = 0; i < postfixTokens.size(); ++i)
    {
        if (areDigits(postfixTokens[i]))
        {
            stack.push(std::stod(postfixTokens[i]));
        }
        else if (operators.find(postfixTokens[i].at(0)) != std::string::npos)
        {
            double x = 0, y = 0;
            stack.pop(x);
            stack.pop(y);
            switch (postfixTokens[i].at(0))
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