#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef> // size_t için

template <typename T, typename F>
void iter(T *arr, const size_t len, F func)
{
    if (!arr)
        return;
    for (size_t i = 0; i < len; ++i)
        func(arr[i]);
}

template <typename T, typename F>
void iter(const T *arr, const size_t len, F func)
{
    if (!arr)
        return;
    for (size_t i = 0; i < len; ++i)
        func(arr[i]);
}

#endif