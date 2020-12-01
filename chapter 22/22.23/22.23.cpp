// 22.23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
#include <vector>

const int MAXSIZE = 256;

int main()
{
    std::vector<char*> cStringVector;

    std::cout << "Input lines, Ctr+Z to stop:\n";

    char* str = new char[MAXSIZE];

    memset((void*)str, '\0', MAXSIZE);
    while (std::cin.getline(str, MAXSIZE))
    {
        cStringVector.push_back(str);

        str = new char[MAXSIZE];
        memset((void*)str, '\0', MAXSIZE);
    }

    for (auto& v : cStringVector)
    {
        if (strlen(v) >= 2 && v[strlen(v)-1] == 'D' && v[strlen(v)-2] == 'E')
        {
            std::cout << v << std::endl;
        }
        delete[] v;
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
