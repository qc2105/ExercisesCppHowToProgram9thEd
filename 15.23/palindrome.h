#pragma once

template<class T>
bool palindrome(std::vector<T>& vec);

template<class T>
bool palindrome(std::vector<T>& vec)
{
    if (vec.empty())
    {
        return true;
    }

    for (size_t i = 0; i < vec.size() / 2; ++i)
    {
        if (vec.at(i) != vec.at(vec.size() - 1 - i))
        {
            return false;
        }
    }

    return true;
}