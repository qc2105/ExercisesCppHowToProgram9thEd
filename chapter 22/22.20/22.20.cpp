// 22.20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
#include <vector>

const int MAXSIZE = 256;

int main()
{
    std::vector<char*> cStringVector;
    size_t lettersCount['z' - 'a' + 1] = { 0 };

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
        for (size_t i = 0; i < strlen(v); ++i)
        {
            ++lettersCount[tolower(v[i]) - 'a'];
        }
        delete[] v;
    }

    for (int i = 0; i < 'z' - 'a' + 1; ++i)
    {
        std::cout << static_cast<char>('a' + i) << '\t' << lettersCount[i] << std::endl;
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
