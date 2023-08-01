#pragma once
//-----------------------------------------------------------------------------
#include "utils.h"
#include <iomanip>
#include <tuple>
#include <type_traits>
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
struct PrintImpl<T, std::enable_if_t<std::is_same_v<int8_t, T>>>
{
    static void print_ip(T value)
    {
        std::cout << (value & 0xFF) << std::endl;
    }
};
//-----------------------------------------------------------------------------
template <class T>
struct PrintImpl<T, std::enable_if_t<std::is_same_v<int16_t, T>>>
{
    static void print_ip(T value)
    {
        std::cout << (double)value << std::endl;
    }
};
//-----------------------------------------------------------------------------
template <class T>
struct PrintImpl<T, std::enable_if_t<std::is_same_v<int32_t, T>>>
{
    static void print_ip(T value)
    {
        print_ip_from_int(value);
    }
};
//-----------------------------------------------------------------------------
template <class T>
struct PrintImpl<T, std::enable_if_t<std::is_same_v<int64_t, T>>>
{
    static void print_ip(T value)
    {
        print_ip_from_int(value);
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
struct PrintImpl<T, std::enable_if_t<std::is_same_v<std::vector<int>, T>>>
{
    static void print_ip(const T &value)
    {
        print_contaner(value);
    }
};
//-----------------------------------------------------------------------------
template <class T>
struct PrintImpl<T, std::enable_if_t<std::is_same_v<std::list<short>, T>>>
{
    static void print_ip(const T& value)
    {
        print_contaner(value);
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
template <typename T>
void printElem(const T& x)
{
    std::cout << x << '.';
};
//-----------------------------------------------------------------------------
template <typename T>
void printElem2(const T& x)
{
    std::cout << x << std::endl;
};
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
