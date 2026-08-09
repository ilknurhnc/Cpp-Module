#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>

int main()
{

    std::vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    std::cout << "----- VECTOR -----" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);

    std::cout << "----- LIST -----" << std::endl;
    try
    {
        std::list<int>::iterator it = easyfind(lst, 25);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }



    std::cout << "----- NOT FOUND -----" << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 100);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}