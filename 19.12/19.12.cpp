// 19.12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Stack.h"

using namespace name19_12;

std::string convertToPostfix(std::string infixStr);

int main()
{
    std::string infixStr = "(6 + 2) * 5 - 8 / 4";
   /* std::string operators = "-+%/*^";
    List<char> postFixList;

    Stack<char> stack;

    stack.push('(');
    infixStr.append(")");

    for (size_t i = 0; !stack.isEmpty() && i < infixStr.size(); ++i)
    {
        if (::isdigit(infixStr[i]))
        {
            postFixList.insertAtBack(infixStr[i]);
        }
        else if (infixStr[i] == '(')
        {
            stack.push(infixStr[i]);
        }
        else if (operators.find(infixStr[i]) != std::string::npos)
        {
            if (operators.find(stack.top()) != std::string::npos && operators.find(infixStr[i]) <= operators.find(stack.top()))
            {
                char c = '\0';
                stack.pop(c);
                postFixList.insertAtBack(c);
            }
            stack.push(infixStr[i]);
        }
        else if (infixStr[i] == ')')
        {
            while (stack.top() != '(')
            {
                char c = '\0';
                stack.pop(c);
                postFixList.insertAtBack(c);
            }
            stack.pop();
        }
    }

    std::cout << postFixList;*/

    std::cout << convertToPostfix(infixStr);

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

std::string convertToPostfix(std::string infixStr)
{
    std::string operators = "-+%/*^";
    List<char> postFixList;

    Stack<char> stack;

    stack.push('(');
    infixStr.append(")");

    for (size_t i = 0; !stack.isEmpty() && i < infixStr.size(); ++i)
    {
        if (::isdigit(infixStr[i]))
        {
            postFixList.insertAtBack(infixStr[i]);
        }
        else if (infixStr[i] == '(')
        {
            stack.push(infixStr[i]);
        }
        else if (operators.find(infixStr[i]) != std::string::npos)
        {
            if (operators.find(stack.top()) != std::string::npos && operators.find(infixStr[i]) <= operators.find(stack.top()))
            {
                char c = '\0';
                stack.pop(c);
                postFixList.insertAtBack(c);
            }
            stack.push(infixStr[i]);
        }
        else if (infixStr[i] == ')')
        {
            while (stack.top() != '(')
            {
                char c = '\0';
                stack.pop(c);
                postFixList.insertAtBack(c);
            }
            stack.pop();
        }
    }

    std::string postfixStr;
    for (size_t i = 0; i < postFixList.size(); ++i)
    {
        postfixStr.append(1, postFixList[i]);
        postfixStr.append(1, ' ');
    }

    return postfixStr;
}
