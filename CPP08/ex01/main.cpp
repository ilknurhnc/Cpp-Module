#include "Span.hpp"

#include <iostream>
#include <vector>

int main()
{
    try
    {
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    try
    {
        Span sp(2);

        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(30);
    }
    catch (const std::exception &e)
    {
        std::cout << "Capacity error: " << e.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    try
    {
        Span sp(5);

        sp.addNumber(42);

        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Not enough numbers: " << e.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    try
    {
        Span sp(5);

        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Empty span: " << e.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    try
    {
        std::vector<int> numbers;

        numbers.push_back(10);
        numbers.push_back(20);
        numbers.push_back(30);
        numbers.push_back(40);
        numbers.push_back(50);

        Span sp(5);

        sp.addNumber(numbers.begin(), numbers.end());

        std::cout << "Range shortest span: " << sp.shortestSpan() << std::endl;

        std::cout << "Range longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}