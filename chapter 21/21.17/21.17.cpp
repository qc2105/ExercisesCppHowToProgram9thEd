// 21.17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>

int main()
{
    std::cout << "Input a sentence:\n\tInput Ctr+Z on Windows to end input.\n";

    std::string inputStr;

    std::map<char, size_t> vowelsCount;
    vowelsCount['a'] = vowelsCount['e'] = vowelsCount['i']
        = vowelsCount['o'] = vowelsCount['u'] = 0;
    while (std::getline(std::cin, inputStr))
    {
        for (auto v : inputStr)
        {
            switch (v)
            {
            case 'a' : 
                vowelsCount['a'] += 1;
                break;
            case 'e' :
                vowelsCount['e'] += 1;
                break;
            case 'i' :
                vowelsCount['i'] += 1;
                break;
            case 'o' :
                vowelsCount['o'] += 1;
                break;
            case 'u' :
                vowelsCount['u'] += 1;
                break;
            default:
                break;
            }
        }
    }

    for (auto v : vowelsCount)
    {
        std::cout << v.first << ": " << v.second << std::endl;
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
