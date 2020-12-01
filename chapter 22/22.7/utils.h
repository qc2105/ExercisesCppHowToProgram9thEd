#pragma once

unsigned power2(unsigned number, unsigned pow);

unsigned power2(unsigned number, unsigned pow)
{
    number <<= pow;
    if (pow >= 32)
    {
        return 0; // overflow?
    }
    return number;
}