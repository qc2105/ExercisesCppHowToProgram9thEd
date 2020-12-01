#pragma once

#include <cstring>

int homeMadeStrcmpV1(const char* str1, const char* str2);
int homeMadeStrcmpV2(const char* str1, const char* str2);
int homeMadeStrncmpV1(const char* str1, const char* str2, size_t count);
int homeMadeStrncmpV2(const char* str1, const char* str2, size_t count);

char* homeMadeStrcpyV1(char* s1, const char* s2);
char* homeMadeStrcpyV2(char* s1, const char* s2);
char* homeMadeStrncpyV1(char* s1, const char* s2, size_t n);
char* homeMadeStrncpyV2(char* s1, const char* s2, size_t n);

char* homeMadeStrcatV1(char* s1, const char* s2);
char* homeMadeStrcatV2(char* s1, const char* s2);
char* homeMadeStrncatV1(char* s1, const char* s2, size_t n);
char* homeMadeStrncatV2(char* s1, const char* s2, size_t n);


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

inline char* homeMadeStrcpyV1(char* s1, const char* s2)
{
    size_t i = 0;
    for (; s2[i] != '\0'; ++i)
    {
        s1[i] = s2[i];
    }
    s1[i] = '\0';

    return s1;
}

inline char* homeMadeStrcpyV2(char* s1, const char* s2)
{
    char* ptr1 = s1;
    const char* ptr2 = s2;
    for (; *ptr2 != '\0'; ++ptr1, ++ptr2)
    {
        *ptr1 = *ptr2;
    }
    *ptr1 = '\0';

    return s1;
}

inline char* homeMadeStrncpyV1(char* s1, const char* s2, size_t n)
{
    size_t i = 0;
    for (; s2[i] != '\0'; ++i)
    {
        s1[i] = s2[i];
    }
    
    for (; i < n; ++i)
    {
        s1[i] = '\0';
    }

    return s1;
}

inline char* homeMadeStrncpyV2(char* s1, const char* s2, size_t n)
{
    char* ptr1 = s1;
    const char* ptr2 = s2;
    size_t i = 0;
    for (; *ptr2 != '\0'; ++ptr1, ++ptr2, ++i)
    {
        *ptr1 = *ptr2;
    }
    
    for (; i < n; ++i, ++ptr1)
    {
        *ptr1 = '\0';
    }

    return s1;
}

inline char* homeMadeStrcatV1(char* s1, const char* s2)
{
    size_t i = 0;
    for (; s1[i] != '\0'; ++i)
    {
        ;
    }
    size_t j = 0;
    for (; s2[j] != '\0'; ++i, ++j)
    {
        s1[i] = s2[j];
    }
    s1[i] = '\0';

    return s1;
}

inline char* homeMadeStrcatV2(char* s1, const char* s2)
{
    char* ptr1 = s1;
    for (; *ptr1 != '\0'; ++ptr1)
    {
        ;
    }
    const char* ptr2 = s2;
    for (; *ptr2 != '\0'; ++ptr1, ++ptr2)
    {
        *ptr1 = *ptr2;
    }
    *ptr1 = '\0';

    return s1;
}

inline char* homeMadeStrncatV1(char* s1, const char* s2, size_t n)
{
    size_t i = 0;
    for (; s1[i] != '\0'; ++i)
    {
        ;
    }
    size_t j = 0;
    for (; s2[j] != '\0' && j < n; ++i, ++j)
    {
        s1[i] = s2[j];
    }
    s1[i] = '\0';

    return s1;
}

inline char* homeMadeStrncatV2(char* s1, const char* s2, size_t n)
{
    char* ptr1 = s1;
    for (; *ptr1 != '\0'; ++ptr1)
    {
        ;
    }
    size_t i = 0;
    const char* ptr2 = s2;
    for (; *ptr2 != '\0' && i < n; ++ptr1, ++ptr2, ++i)
    {
        *ptr1 = *ptr2;
    }
    *ptr1 = '\0';

    return s1;
}
