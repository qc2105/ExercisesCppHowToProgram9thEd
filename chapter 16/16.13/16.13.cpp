// 16.13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <cctype>

bool palindromeTester(std::string str);
void makeLower(char& c);

int main()
{
    std::cout << std::boolalpha << palindromeTester("Radar") << std::endl;
    std::cout << std::boolalpha << palindromeTester("hello world") << std::endl;
    std::cout << std::boolalpha << palindromeTester("(!!able was I ,ere; i:) saw elba.") << std::endl;

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

bool palindromeTester(std::string str)
{
    std::string stripped;

    std::copy_if(str.begin(), str.end(), std::back_inserter(stripped), ::isalpha);

    std::for_each(stripped.begin(), stripped.end(), makeLower);

    std::string temp = stripped;
    
    std::reverse(temp.begin(), temp.end());

    if (temp == stripped)
    {
        return true;
    }

    return false;
}

void makeLower(char& c)
{
    c = ::tolower(c);
}
