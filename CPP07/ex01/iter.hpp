#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>
#include <cstddef>


template<typename Type>
void print(const Type& val)
{
    std::cout << val << " "; 
}

template<typename Type>
void add(Type& val)
{
    val++; 
}

void append_world(std::string& str)
{
    str += "_ADD";
}


template<typename Type, typename Function>
void iter(Type* arr, size_t len, Function func)
{
    if(!arr)
        return; 
        
    for(size_t i = 0; i < len; ++i)
        func(arr[i]);
}

template<typename Type, typename Function>
void iter(const Type* arr, size_t len, Function func)
{
    if(!arr)
        return;
        
    for(size_t i = 0; i < len; ++i)
        func(arr[i]);
}

#endif