// 20.9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <algorithm>

template <class T, int size>
int recursiveBinarySearch(std::array<T, size>& items, const T& key, int startIndex, int endIndex);

template <class T, int size>
void recursiveBinarySearchHelpler(std::array<T, size>& items, const T& key, int startIndex, int endIndex, int& resultLocation);

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    std::array<int, 10> array1;

    int key = rand() % 10;

    for (int i = 0; i < 10; ++i)
    {
        array1[i] = rand() % 10;
    }

    array1[rand() % 10] = key;
    std::sort(std::begin(array1), std::end(array1));

    for (auto v : array1)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    int pos = recursiveBinarySearch(array1, key, 0, 9);
    std::cout << key << " at " << pos << std::endl;

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

template<class T, int size>
int recursiveBinarySearch(std::array<T, size>& items, const T& key, int startIndex, int endIndex)
{
    int result = -1;
    recursiveBinarySearchHelpler(items, key, startIndex, endIndex, result);
    return result;
}

template<class T, int size>
void recursiveBinarySearchHelpler(std::array<T, size>& items, const T& key, int startIndex, int endIndex, int& resultLocation)
{
    if (endIndex >= startIndex)
    {
        int middle = (startIndex + endIndex + 1) / 2;
        if (key == items.at(middle))
        {
            resultLocation = middle;
            return;
        }
        recursiveBinarySearchHelpler(items, key, startIndex, middle - 1, resultLocation);
        recursiveBinarySearchHelpler(items, key, middle + 1, endIndex, resultLocation);
    }
    
}
