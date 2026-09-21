#include "Span.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <map>

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

        std::cout << "Shortest span: "
                  << sp.shortestSpan() << std::endl;

        std::cout << "Longest span: "
                  << sp.longestSpan() << std::endl;
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

        std::cout << "Vector range shortest span: " << sp.shortestSpan() << std::endl;

        std::cout << "Vector range longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: "
                  << e.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;


    try
    {
        std::list<int> numbers;

        numbers.push_back(100);
        numbers.push_back(200);
        numbers.push_back(300);
        numbers.push_back(400);
        numbers.push_back(500);

        Span sp(5);

        sp.addNumber(numbers.begin(), numbers.end());

        std::cout << "List range shortest span: " << sp.shortestSpan() << std::endl;

        std::cout << "List range longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;


    try
    {
        std::map<int, int> numbers;

        numbers[0] = 50;
        numbers[1] = 10;
        numbers[2] = 30;
        numbers[3] = 20;
        numbers[4] = 40;

        std::vector<int> values;

        for (std::map<int, int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
        {
            values.push_back(it->second);
        }

        Span sp(5);

        sp.addNumber(values.begin(), values.end());

        std::cout << "Map shortest span: " << sp.shortestSpan() << std::endl;

        std::cout << "Map longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "--------------------" << std::endl;


    try
    {
        std::vector<int> numbers;

        for (int i = 0; i < 10000; ++i)
            numbers.push_back(i);

        Span sp(10000);

        sp.addNumber(numbers.begin(), numbers.end());

        std::cout << "10000 numbers shortest span: " << sp.shortestSpan() << std::endl;

        std::cout << "10000 numbers longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}