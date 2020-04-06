// 6.39.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <array>
#include <utility>
#include <vector>
#include <queue>
#include <list>
#include <chrono>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <string>
#include "Clock.h"

//move n Hanoi disks from peg1 to peg3, ierative version.
void move(size_t n);

int main()
{
    int n = 0;
    while (true)
    {
        std::cout << "How many disks? " << std::endl;
        std::cin >> n;
        if (n < 0)
        {
            break;
        }

        auto start = std::chrono::high_resolution_clock().now();

        move(n);

        auto end = std::chrono::high_resolution_clock().now();

        auto duriation = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
        std::cout << "It took me: " << duriation.count() << " seconds" << std::endl;
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

bool isValid(std::pair<int, int> step, std::array<std::vector<size_t>, 3>& stacks)
{
    int fromPeg = step.first - 1;
    int toPeg = step.second - 1;

    if (stacks.at(fromPeg).empty())
    {
        return false;
    }
    if (!stacks.at(toPeg).empty() && stacks.at(fromPeg).back() > stacks.at(toPeg).back())
    {
        return false;
    }

    return true;
}

void initializeStacks(size_t n, std::array<std::vector<size_t>, 3>& stacks)
{
    for (size_t i = 0; i < stacks.size(); ++i)
    {
        stacks.at(i).clear();
    }
    // Initial state: n disks on peg1, the smaller the disk, the upper the disk's position is.
    for (size_t i = n; i >= 1; --i)
    {
        stacks.at(0).push_back(i);
    }
}

void executeStep(std::pair<int, int> step, std::array<std::vector<size_t>, 3>& stacks)
{
    size_t disk = 0;
    int fromPeg = step.first - 1;
    int toPeg = step.second - 1;

    disk = stacks.at(fromPeg).back();
    stacks.at(fromPeg).pop_back();
    stacks.at(toPeg).push_back(disk);
}

void move(size_t n)
{  
    std::array<std::pair<int, int>, 6> stepPermutations =
    {
        std::pair<int, int>(1, 2),
        std::pair<int, int>(1, 3),
        std::pair<int, int>(2, 1),
        std::pair<int, int>(2, 3),
        std::pair<int, int>(3, 1),
        std::pair<int, int>(3, 2)
    };

    // With some math we can get this formula from the recursive version: for n disks we need 2^n - 1 steps
    // We use a Clock object to store the steps. 
    std::array<std::vector<size_t>, 3> stacks;
    Clock clock(n);
    double nPermutations = ::pow(6, ::pow(2, n) - 1);
    
    std::string nPermutaionsStr = std::to_string(nPermutations);
   
    for (double i = 0; i < nPermutations; ++i)
    {
        std::cout << std::to_string(i) << '/' << nPermutaionsStr << '\r';
        initializeStacks(n, stacks);
        for (size_t j = 0; j < clock.size(); ++j) // ::pow(2, n) - 1 times.
        {
            if (isValid(stepPermutations.at(clock.at(j)), stacks))
            {
                executeStep(stepPermutations.at(clock.at(j)), stacks);
            }
            else
            {
                break;
            }
        }
        if (stacks.at(2).size() == n && stacks.at(2).back() == 1)
        {
            std::cout << std::endl;
            for (size_t j = 0; j < clock.size(); ++j)
            {
                std::cout << stepPermutations.at(clock.at(j)).first << "->" << stepPermutations.at(clock.at(j)).second << std::endl;
            }
            break;
        }
        ++clock;
    }
}
