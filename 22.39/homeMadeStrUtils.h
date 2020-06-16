#pragma once

#include <cstring>

int homeMadeStrcmpV1(const char* str1, const char* str2);
int homeMadeStrcmpV2(const char* str1, const char* str2);
int homeMadeStrncmpV1(const char* str1, const char* str2, size_t count);
int homeMadeStrncmpV2(const char* str1, const char* str2, size_t count);

int homeMadeStrcmpV1(const char* str1, const char* str2)
{
    const char* ptr1 = nullptr;
    const char* ptr2 = nullptr;
    for ( ptr1 = str1, ptr2 = str2; *ptr1 != '\0' && *ptr2 != '\0'; ++ptr1, ++ptr2)
    {
        if (*ptr1 > * ptr2)
        {
            return 1;
        }
        else if (*ptr1 < *ptr2)
        {
            return -1;
        }
    }

    if (*ptr1 > * ptr2)
    {
        return 1;
    }
    else if (*ptr1 < *ptr2)
    {
        return -1;
    }
   
    return 0;
}

int homeMadeStrcmpV2(const char* str1, const char* str2)
{
    size_t i = 0;

    for (; str1[i] != '\0' && str2[i] != '\0'; ++i)
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return -1;
        }
    }
    
    if (str1[i] > str2[i])
    {
        return 1;
    }
    else if (str1[i] < str2[i])
    {
        return -1;
    }
    
    return 0;
}

inline int homeMadeStrncmpV1(const char* str1, const char* str2, size_t count)
{
    const char* ptr1 = nullptr;
    const char* ptr2 = nullptr;
    size_t i = 0;
    for (ptr1 = str1, ptr2 = str2; *ptr1 != '\0' && *ptr2 != '\0' && i < count; ++ptr1, ++ptr2, ++i)
    {
        if (*ptr1 > * ptr2)
        {
            return 1;
        }
        else if (*ptr1 < *ptr2)
        {
            return -1;
        }
    }
    
    if (i == count)
    {
        return 0;
    }
    else if (*ptr1 > * ptr2)
    {
        return 1;
    }
    else if (*ptr1 < *ptr2)
    {
        return -1;
    }

    return 0;
}

inline int homeMadeStrncmpV2(const char* str1, const char* str2, size_t count)
{
    size_t i = 0;

    for (; str1[i] != '\0' && str2[i] != '\0' && i < count; ++i)
    {
        if (str1[i] > str2[i])
        {
            return 1;
        }
        else if (str1[i] < str2[i])
        {
            return -1;
        }
    }

    if (i == count)
    {
        return 0;
    }
    else if (str1[i] > str2[i])
    {
        return 1;
    }
    else if (str1[i] < str2[i])
    {
        return -1;
    }

    return 0;
}
