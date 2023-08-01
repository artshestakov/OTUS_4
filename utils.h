#pragma once
//-----------------------------------------------------------------------------
#include <iostream>
#include <array>
#include <vector>
#include <list>
//-----------------------------------------------------------------------------
template<typename T>
void print_ip_from_int(T value)
{
    constexpr int array_size = sizeof(value);
    std::array<int, array_size> arr;

    for (int i = 0, c = sizeof(value), step = 0; i < c; ++i, step += 8)
    {
        arr[i] = step == 0 ?
            (int)(value & 0xFF) :
            (int)((value >> step) & 0xFF);
    }
    
    for (int i = array_size - 1; i >= 0; --i)
    {
        std::cout << arr[i] << (i > 0 ? '.' : '\n');
    }
}
//-----------------------------------------------------------------------------
template<typename T>
void print_contaner(const T& contaner)
{
    for (auto It = contaner.begin(); It != contaner.end(); ++It)
    {
        std::cout << *It << (It != std::prev(contaner.end()) ? '.' : '\n');
    }
}
//-----------------------------------------------------------------------------
