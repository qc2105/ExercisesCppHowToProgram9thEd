#pragma once

#include <iostream>

void displayBits(unsigned integer);
unsigned packCharacters(char chars[4]);

void displayBits(unsigned integer)
{
    const unsigned SHIFT = 8 * sizeof(unsigned) - 1;
    const unsigned MASK = 1 << SHIFT;

    for (unsigned i = 0; i < 8 * sizeof(int); i++)
    {
        unsigned bitV = integer & MASK;
        std::cout << (bitV ? 1 : 0);
        if ((i+1) % 8 == 0 && i != 0)
        {
            std::cout << ' ';
        }
        integer <<= 1;
    }
    std::cout << std::endl;
}

inline unsigned packCharacters(char chars[4])
{
    unsigned packStore;
    packStore = chars[0];
    for (int i = 1; i < 4; i++)
    {
        packStore <<= 8;
        packStore ^= chars[i];
    }

    return packStore;
}

