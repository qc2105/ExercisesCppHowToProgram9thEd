// 22.25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>

namespace name22_25{
int isdigit(int c);
int isalpha(int c);
int isalnum(int c);
int isxdigit(int c);
int islower(int c);
int isupper(int c);
int tolower(int c);
int toupper(int c);
int isspace(int c);
int iscntrl(int c);
int ispunct(int c);
int isprint(int c);
int isgraph(int c);
}

int main()
{
    std::cout << ::isprint(127) << std::endl;
    std::cout << name22_25::isprint(127) << std::endl;
    std::cout << name22_25::ispunct('1') << std::endl;
    std::cout << name22_25::ispunct('@') << std::endl;

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

namespace name22_25 {
    int isdigit(int c)
    {
        return c >= static_cast<int>('0') && c <= static_cast<int>('9');
    }

    int isalpha(int c)
    {
        bool isLower = c >= static_cast<int>('a') && c <= static_cast<int>('z');
        bool isUpper = c >= static_cast<int>('A') && c <= static_cast<int>('Z');
        return isLower || isUpper;
    }

    int isalnum(int c)
    {
        return isdigit(c) || isalpha(c);
    }

    int isxdigit(int c)
    {
        bool isHexAlphaLower = c >= static_cast<int>('a') && c <= static_cast<int>('f');
        bool isHexAlphaUpper = c >= static_cast<int>('A') && c <= static_cast<int>('F');
        return isdigit(c) || isHexAlphaLower || isHexAlphaUpper;
    }

    int islower(int c)
    {
        return c >= static_cast<int>('a') && c <= static_cast<int>('z');
    }

    int isupper(int c)
    {
        return c >= static_cast<int>('A') && c <= static_cast<int>('Z');
    }

    int tolower(int c)
    {
        int result = c;
        if (isupper(c))
        {
            result = c - static_cast<int>('A') + static_cast<int>('a');
        }

        return result;
    }

    int toupper(int c)
    {
        int result = c;
        if (islower(c))
        {
            result = c - static_cast<int>('a') + static_cast<int>('A');
        }

        return result;
    }

    int isspace(int c)
    {
        return c == static_cast<int>('\n') || c == static_cast<int>(' ') || c == static_cast<int>('\f') || c == static_cast<int>('\r') ||
            c == static_cast<int>('\t') || c == static_cast<int>('\v');
    }

    int iscntrl(int c)
    {
        return c == static_cast<int>('\n') || c == static_cast<int>('\f') || c == static_cast<int>('\r') || c == static_cast<int>('\t') ||
            c == static_cast<int>('\v') || c == static_cast<int>('\a') || c == static_cast<int>('\b');
    }

    int ispunct(int c)
    {
        return isprint(c) && !isalnum(c) && c != static_cast<int>(' ');
    }

    int isprint(int c)
    {
        return c >= 32 && c < 127;
    }

    int isgraph(int c)
    {
        return isprint(c) && c != static_cast<int>(' ');
    }
}