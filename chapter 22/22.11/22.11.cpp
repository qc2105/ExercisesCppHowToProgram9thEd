// 22.11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>

int main()
{
    char c = '\0';
    std::cout << "Please input a character:\n";

    while (std::cin >> c)
    {
        std::cout << c << " is " << (isalnum(c) ? "" : "not ") << "an alphabet or a number\n";    
        std::cout << c << " is " << (isalpha(c) ? "" : "not ") << "an alpha\n";
        std::cout << c << " is " << (iscntrl(c) ? "" : "not ") << "a control character\n";
        std::cout << c << " is " << (isdigit(c) ? "" : "not ") << "a digit\n";
        std::cout << c << " is " << (isgraph(c) ? "" : "not ") << "a graph character\n";
        std::cout << c << " is " << (islower(c) ? "" : "not ") << "a lower character\n";
        std::cout << c << " is " << (isprint(c) ? "" : "not ") << "printable\n";
        std::cout << c << " is " << (ispunct(c) ? "" : "not ") << "a punctuation mark\n";
        std::cout << c << " is " << (isspace(c) ? "" : "not ") << "a space character\n";
        std::cout << c << " is " << (isupper(c) ? "" : "not ") << "an upper character\n";
        std::cout << c << " is " << (isxdigit(c) ? "" : "not ") << "an hex digit character\n";
        std::cout << c << " is " << (isblank(c) ? "" : "not ") << "blank\n";
        std::cout << c << " toupper is " << static_cast<char>(toupper(c)) << std::endl;
        std::cout << c << " tolower is " << static_cast<char>(tolower(c)) << std::endl;

        std::cout << "Please input a character:\n";
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
