// 18.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

template<class T>
bool isEqualTo(T a, T b);

class Element
{
public:
    explicit Element(int v) :
        data(v)
    {

    }

    bool operator==(Element& b)
    {
        return data == b.data;
    }

private:
    Element();
    int data;
};

int main()
{
    std::cout << "Is 5 == 5?: " << std::boolalpha << isEqualTo<int>(5, 5) << std::endl;
    std::cout << "Is 5.3 == 5.2?: " << std::boolalpha << isEqualTo<double>(5.3, 5.2) << std::endl;
    std::cout << "Is \"China\" == \"China\"?: " << std::boolalpha << isEqualTo<std::string>("China", "China") << std::endl;

    std::cout << "Is Element(5) == Element(5)?: " << std::boolalpha << isEqualTo<Element>(Element(5), Element(5)) << std::endl;
    std::cout << "Is Element(5) == Element(6)?: " << std::boolalpha << isEqualTo<Element>(Element(5), Element(6)) << std::endl;

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

template<class T>
bool isEqualTo(T a, T b)
{
    return a == b;
}
