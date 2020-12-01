// 22.38.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../22.39/homeMadeStrUtils.h"
#include <cstdlib>

int main()
{
    const int SIZE = 100;
    char s1[SIZE] = { '\0' };
    const char* s2 = "Hello World! ";
    const char* s3 = "Hello Universe!";
    
    std::cout << homeMadeStrcpyV1(s1, s2) << std::endl;
    std::cout << homeMadeStrcatV1(s1, s3) << std::endl;
    memset((void*)s1, 0, SIZE);
    std::cout << homeMadeStrcpyV2(s1, s2) << std::endl;
    std::cout << homeMadeStrcatV2(s1, s3) << std::endl;
    memset((void*)s1, 0, SIZE);
    std::cout << homeMadeStrncpyV1(s1, s2, strlen(s2)) << std::endl;
    std::cout << homeMadeStrncatV1(s1, s3, strlen(s3)) << std::endl;
    memset((void*)s1, 0, SIZE);
    std::cout << homeMadeStrncpyV2(s1, s2, strlen(s2)) << std::endl;
    std::cout << homeMadeStrncatV2(s1, s3, strlen(s3)) << std::endl;
 
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
