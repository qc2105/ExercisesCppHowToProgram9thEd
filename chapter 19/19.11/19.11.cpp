// 19.11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Stack.h"

using namespace name19_11;

bool isPalindrome(std::string& str);
bool isPalindrome(const char* cstr);

int main()
{
    std::cout << "Is 'what' a palidrome? " << std::boolalpha << isPalindrome("what") << std::endl;
    std::cout << "Is 'eye! eye?' a palidrome? " << isPalindrome("eye! eye?") << std::endl;

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

bool isPalindrome(std::string& str)
{
    std::string stripped;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (::isalnum(str.at(i)))
        {
            stripped.push_back(str.at(i));
        }
    }

    std::string reversed;
    Stack<char> stack;
    for (auto& c : stripped)
    {
        stack.push(c);
    }
    while (!stack.isEmpty())
    {
        char ch = '\0';
        stack.pop(ch);
        reversed.push_back(ch);
    }

    return stripped == reversed;
}

bool isPalindrome(const char* cstr)
{
    std::string temp = std::string(cstr);
    return isPalindrome(temp);
}
