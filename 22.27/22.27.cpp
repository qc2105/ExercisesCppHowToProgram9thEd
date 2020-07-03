// 22.27.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

char* myStrchr(const char* s, int c);
char* myStrrchr(const char* s, int c);

int main()
{
    const char* hello = "Hello World!\n";

    std::cout << myStrchr(hello, 'W') << "\t vs " << strchr(hello, 'W');
    std::cout << myStrrchr(hello, 'o') << "\t vs " << strrchr(hello, 'o');

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

char* myStrchr(const char* s, int c)
{
    for (char* ptr = const_cast<char*>(s); *ptr != '\0'; ++ptr)
    {
        if (*ptr == static_cast<char>(c))
        {
            return ptr;
        }
    }
    return nullptr;
}

char* myStrrchr(const char* s, int c)
{
    char* start = const_cast<char*>(s);
    char* end = nullptr;
    for (end = start; *end != '\0'; ++end)
    {
        ;
    }
    char* ptr = nullptr;
    for (char* ptr = end; ptr != start; --ptr)
    {
        if (*ptr == static_cast<char>(c))
        {
            return ptr;
        }
    }
    if ( (ptr != nullptr) && (*ptr == static_cast<char>(c)) )
    {
        return ptr;
    }
    return nullptr;
}
