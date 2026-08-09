#include "Span.hpp"

#include <algorithm>

Span::Span() : maxSize(0){}

Span::Span(unsigned int n) : maxSize(n){}

Span::Span(const Span &other)
{
    maxSize = other.maxSize;
    num = other.num;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        maxSize = other.maxSize;
        num = other.num;
    }
    return *this;
}

Span::~Span(){}

void Span::addNumber(int number)
{
    if (num.size() >= maxSize)
        throw std::runtime_error("Span is full");

    num.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (num.size() < 2)
        throw std::runtime_error("Not enough numbers");

    std::vector<int> temp = num;

    std::sort(temp.begin(), temp.end());

    unsigned int shortest = static_cast<unsigned int>(-1);

    for (std::vector<int>::size_type i = 0; i + 1 < temp.size(); i++)
    {
        unsigned int difference = static_cast<unsigned int>(static_cast<long long>(temp[i + 1]) - static_cast<long long>(temp[i]));

        if (difference < shortest)
            shortest = difference;
    }

    return shortest;
}

unsigned int Span::longestSpan() const
{
    if (num.size() < 2)
        throw std::runtime_error("Not enough numbers");

    std::vector<int>::const_iterator min;
    std::vector<int>::const_iterator max;

    min = std::min_element(num.begin(), num.end());
    max = std::max_element(num.begin(), num.end());

    return static_cast<unsigned int>(static_cast<long long>(*max) - static_cast<long long>(*min));
}