#pragma once
#include <iostream>
#include <array>

template <class T, size_t size>
void swap(std::array<T, size>& items, size_t i, size_t j)
{
    T temp = items.at(i);
    items.at(i) = items.at(j);
    items.at(j) = temp;
}

template <class T, size_t size>
size_t partition(std::array<T, size>& items, size_t start, size_t end)
{
    size_t last = start;
    size_t mark = end + 1;
    bool leftOk = true;
    bool rightOk = true;

    while (true)
    {
        /*for (auto v : items)
        {
            std::cout << v << " ";
        }
        std::cout << "\t\t" << last << std::endl;*/
        rightOk = true;
        leftOk = true;
        for (size_t i = mark > 0 ? mark - 1 : 0; i > last; --i)
        {
            if (items.at(i) < items.at(last))
            {
                rightOk = false;
                swap(items, i, last);
                mark = last;
                last = i;
                break;
            }
        }
        for (size_t i = mark + 1; i < last; ++i)
        {
            if (items.at(i) > items.at(last))
            {
                leftOk = false;
                swap(items, i, last);
                mark = last;
                last = i;
                break;
            }
        }
        if (leftOk && rightOk)
        {
            return last;
        }
    }

    return last;
}

template <class T, size_t size>
void quickSort(std::array<T, size>& items, size_t start, size_t end)
{
    if (end > start)
    {
        size_t last = partition(items, start, end);
        quickSort(items, start, last > 0 ? last - 1 : 0);
        quickSort(items, last + 1, end);
    }
}