// 23.9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Base
{
public:

    Base(int argInt)
        :argInt(argInt)
    {
    }

    virtual void print() = 0;
    
protected:
    int argInt;
};

class DerivedLevel1_1 : virtual public Base
{
public:
    DerivedLevel1_1()
        :Base(1)
    {}

    virtual void print() override
    {
        std::cout << typeid(*this).name() << ": " << Base::argInt << std::endl;
    }
};

class DerivedLevel1_2 : virtual public Base
{
public:
    DerivedLevel1_2()
        :Base(1)
    {}

    virtual void print() override
    {
        std::cout << typeid(*this).name() << ": " << Base::argInt << std::endl;
    }
};

class DerivedLevel2_1 : public DerivedLevel1_1, public DerivedLevel1_2
{
public:
    DerivedLevel2_1()
        :Base(2)
    {
    }

    virtual void print() override
    {
        std::cout << typeid(*this).name() << ": " << Base::argInt << std::endl;
    }
};


int main()
{
    DerivedLevel1_1 level11;
    DerivedLevel1_2 level12;
    
    DerivedLevel2_1 level21;

    Base* ptr[3] = { nullptr };
    ptr[0] = &level11;
    ptr[1] = &level12;
    ptr[2] = &level21;

    for (int i = 0; i < 3; ++i)
    {
        ptr[i]->print();
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
