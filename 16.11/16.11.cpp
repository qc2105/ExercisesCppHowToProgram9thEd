// 16.11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>

int main()
{
    std::cout << "Hello World!\n";

    std::list<std::string> list_a = { "1", "2", "3", "4", "5", "6" };
    std::list<std::string> list_b = { "8", "9" , "10", "22", "23", "99" };

    list_a.sort();
    list_b.sort();

    std::list<std::string> list_c;

    std::merge(list_a.begin(), list_a.end(), list_b.begin(), list_b.end(), std::back_inserter(list_c));

    std::ostream_iterator<std::string> out(std::cout, " ");

    std::copy(list_c.begin(), list_c.end(), out);

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
