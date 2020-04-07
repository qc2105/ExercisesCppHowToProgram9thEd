// 19.15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>
#include "Queue.h"

using namespace name19_15;
size_t getRandom(int rangeStart, int rangeEnd);
std::pair<size_t, size_t> simulation(int rangeStart, int rangeEnd);

class Customer
{
public:
    Customer(void) :
        enQueClock(0)
    {}

    Customer(size_t worldClock) :
        enQueClock(worldClock)
    {
    }

    size_t getQueTime(size_t deQueClock) const
    {
        return deQueClock - enQueClock;
    }

private:
    size_t enQueClock;
};



int main()
{
    std::pair<size_t, size_t> result = simulation(1, 4);
    std::cout << "The maximum number of customers in the queue at any time: " << result.first << std::endl;
    std::cout << "The longest wait any one customer experiences: " << result.second << " minutes." << std::endl;

    std::cout << "----------------If arrival interval is changed to: 1~3--------------------\n";
    result = simulation(1, 3);
    std::cout << "The maximum number of customers in the queue at any time: " << result.first << std::endl;
    std::cout << "The longest wait any one customer experiences: " << result.second << " minutes." << std::endl;

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

size_t getRandom(int rangeStart, int rangeEnd)
{
    int newEnd = rangeEnd - rangeStart;

    return static_cast<size_t>(rand()) % (static_cast<size_t>(newEnd) + 1) + rangeStart;
}

std::pair<size_t, size_t> simulation(int rangeStart, int rangeEnd)
{
    Queue<Customer> que;
    srand(static_cast<unsigned int>(time(NULL)));

    size_t maxQueSize = 0, longestWaitTime = 0;

    size_t worldClock = 0;

    size_t arrivalClock = worldClock + getRandom(rangeStart, rangeEnd);
    

    for (; worldClock != arrivalClock; ++worldClock)
    {
    }
   
    size_t  serviceClock = worldClock + getRandom(1, 4);
    arrivalClock = worldClock + getRandom(rangeStart, rangeEnd);

    for (; worldClock < 720; ++worldClock)
    {
        if (worldClock = arrivalClock)
        {
            //std::cout << "A new customer has arrived\n";
            Customer newCustomerArrived(worldClock);
            que.enqueue(newCustomerArrived);
            arrivalClock = worldClock + getRandom(rangeStart, rangeEnd);
        }

        if (que.size() > maxQueSize)
        {
            maxQueSize = que.size();
        }

        if (worldClock == serviceClock)
        {
            //std::cout << "Service was completed for the last customer\n";
            Customer newCustomerToService;
            que.dequeue(newCustomerToService);
            if (newCustomerToService.getQueTime(worldClock) > longestWaitTime)
            {
                longestWaitTime = newCustomerToService.getQueTime(worldClock);
            }
            serviceClock = getRandom(1, 4) + worldClock;
        }
    }

    std::pair<size_t, size_t> result;
    result.first = maxQueSize;
    result.second = longestWaitTime;

    return result;
}
