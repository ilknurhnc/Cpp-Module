#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename Swap>
void swap(Swap& a, Swap& b)
{
    Swap temp = a;
    a = b;
    b = temp;
}

template<typename Min>
Min min(Min a, Min b)
{
    if (a < b)
        return a;
    return b;
}

template<typename Max>
Max max(Max a, Max b)
{
    if (a > b)
        return a;
    return b;
}

#endif