// E11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

inline double sphereVolume(double r);

template <class T>
inline void sum(T x, T y);

template <class T>
inline T minimum2(T x, T y);

template <class T>
inline T minimum3(T x, T y, T z);

template <class T>
void print(T v);

template <class T>
void printArray(T* Array, size_t n);

template <class T>
T summary(T* Array, size_t n);

int main()
{
    for (int i = 1; i <= 10; ++i)
    {
        std::cout << sphereVolume(i) << '\n';
    }

    sum(8, 5);

    double a;
    double b;

    std::cout << "Input two number: \n";

    std::cin >> a >> b;

    std::cout << "The smaller one is: " << minimum2(a, b) << std::endl;

    double x = 0, y = 0, z = 0;

    std::cout << "Input 3 numbers:\n";

    std::cin >> x >> y >> z;

    std::cout << "The smallest number is: " << minimum3(x, y, z) << std::endl;

    const char* hello = "Hello, World!\n";

    print(hello);

    int integer[5] = { 1, 2, 3, 4, 5 };
    printArray(integer, 5);

    std::cout << "\n" << summary(integer, 5) << '\n';

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

inline double sphereVolume(double r)
{
    return (4.0 / 3) * 3.14159 * r * r * r;
}

template <class T>
void sum(T a, T b)
{
    std::cout << "The sum of " << a << " and " << b << " is " << a + b << std::endl;
}

template<class T>
inline T minimum2(T x, T y)
{
    return x < y ? x : y;
}

template<class T>
inline T minimum3(T x, T y, T z)
{
    return minimum2(minimum2(x, y), z);
}

template<class T>
void print(T v)
{
    std::cout << v;
}

template<class T>
void printArray(T* Array, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        std::cout << Array[i];
    }
}

template<class T>
T summary(T* Array, size_t n)
{
    T sum = 0; 
    for (size_t i = 0; i < n; ++i)
    {
        sum += Array[i];
    }

    return sum;
}
