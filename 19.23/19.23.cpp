// 19.23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include "Tree.h"

using namespace name19_23;

int main()
{
    std::stringstream inputs("H e l l o W o r l d !");

    Tree<char> tree;

    inputs >> tree;

    std::cout << "The tree is: " << tree;

    char c = '\0';

    std::cout << "Please input the charactor(except 'q' to quit) to search: " << std::endl;
    while (std::cin >> c)
    {
        if (c == 'q')
        {
            break;
        }

        TreeNode<char>* ptr = nullptr;

        ptr = tree.binaryTreeSearch(c);

        if (ptr)
        {
            std::cout << "There is it: " << ptr->data << " at: " << std::hex << ptr << std::endl;
        }
        else
        {
            std::cout << c << " is not in the tree.\n";
        }

        std::cout << "Please input the charactor(except 'q' to quit) to search: " << std::endl;
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
