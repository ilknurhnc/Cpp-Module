#include <iostream>
#include <string>
#include <cstddef>
#include "iter.hpp"

template<typename Type>
void print_array(const std::string& msg, const Type* arr, size_t len)
{
    std::cout << "\n[" << msg << "]: ";
    ::iter(arr, len, print<Type>);
    std::cout << std::endl;
}

int main()
{
    int int_arr[] = {10, 20, 30};
    size_t int_len = sizeof(int_arr) / sizeof(int_arr[0]);

    print_array("Başlangıç", int_arr, int_len);
    ::iter(int_arr, int_len, add<int>);
    print_array("Artırma Sonrası", int_arr, int_len);

    std::string str_arr[] = {"C++", "Module", "Iter"};
    size_t str_len = sizeof(str_arr) / sizeof(str_arr[0]);

    print_array("Başlangıç", str_arr, str_len);
    ::iter(str_arr, str_len, append_world); 
    print_array("Ekleme Sonrası", str_arr, str_len); 
    
    const int const_arr[] = {100, 200, 300};
    size_t const_len = sizeof(const_arr) / sizeof(const_arr[0]);

    std::cout << "Const Array Elemanları: ";
    ::iter(const_arr, const_len, print<int>);
    std::cout << std::endl;

    return 0;
}