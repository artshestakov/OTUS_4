#pragma once
//-----------------------------------------------------------------------------
#include <iomanip>
#include <tuple>
#include <type_traits>
#include <array>
#include <vector>
#include <list>
#include <iostream>
//-----------------------------------------------------------------------------
template <class T, class Enable = void>
struct PrintImpl
{
    static void print_ip(T value)
    {

    }
};
//-----------------------------------------------------------------------------
template <class T>
struct PrintImpl<T, std::enable_if_t<
    std::is_same_v<int8_t, T> ||
    std::is_same_v<int16_t, T> ||
    std::is_same_v<int32_t, T> ||
    std::is_same_v<int64_t, T>>>
{
    static void print_ip(T value)
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
};
//-----------------------------------------------------------------------------
template <class T>
struct PrintImpl<T, std::enable_if_t<std::is_same_v<std::string, T>>>
{
    static void print_ip(const T &value)
    {
        std::cout << value << std::endl;
    }
};
//-----------------------------------------------------------------------------
template <class T>
struct PrintImpl<T, std::enable_if_t<std::is_same_v<std::vector<int>, T> || std::is_same_v<std::list<short>, T>>>
{
    static void print_ip(const T& contaner)
    {
        for (auto It = contaner.begin(); It != contaner.end(); ++It)
        {
            std::cout << *It << (It != std::prev(contaner.end()) ? '.' : '\n');
        }
    }
};
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <class T>
void print_ip(T value)
{
    PrintImpl<T>::print_ip(std::forward<T>(value));
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
template <typename TupleT, std::size_t... Is>
void print_tuple_ip_impl(const TupleT& tp, std::index_sequence<Is...>)
{
    (..., (std::cout << (Is == 0 ? "" : ".") << std::get<Is>(tp)));
    std::cout << std::endl;
}
//-----------------------------------------------------------------------------
template <typename TupleT, std::size_t TupSize = std::tuple_size_v<TupleT>>
void print_tuple_ip(const TupleT& tp)
{
    print_tuple_ip_impl(tp, std::make_index_sequence<TupSize>{});
}
//-----------------------------------------------------------------------------
