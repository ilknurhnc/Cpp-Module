#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <climits>
#include <cctype>
#include <ctime>

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }

    return *this;
}

PmergeMe::~PmergeMe(){}

bool PmergeMe::parseNumber(const std::string& str,int& number) const
{
    if (str.empty())
        return false;

    for (std::size_t i = 0; i < str.length(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
    }

    std::istringstream iss(str);
    long value;

    if (!(iss >> value))
        return false;

    char extra;

    if (iss >> extra)
        return false;

    if (value <= 0 || value > INT_MAX)
        return false;

    number = static_cast<int>(value);

    return true;
}

bool PmergeMe::parseInput(int argc, char **argv)
{
    if (argc < 2)
        return false;

    _vector.clear();
    _deque.clear();

    for (int i = 1; i < argc; ++i)
    {
        int number;

        if (!parseNumber(argv[i], number))
            return false;

        _vector.push_back(number);
        _deque.push_back(number);
    }

    return true;
}

std::vector<std::size_t>
PmergeMe::generateInsertionOrder(std::size_t size) const
{
    std::vector<std::size_t> order;

    if (size == 0)
        return order;

    if (size <= 1)
        return order;

    std::size_t previousJacob = 1;
    std::size_t currentJacob = 3;

    while (previousJacob < size)
    {
        std::size_t upper = currentJacob;

        if (upper > size)
            upper = size;

        for (std::size_t i = upper; i > previousJacob; --i)
            order.push_back(i - 1);

        std::size_t nextJacob =
            currentJacob + 2 * previousJacob;

        previousJacob = currentJacob;
        currentJacob = nextJacob;
    }

    return order;
}

std::vector<int>::iterator
PmergeMe::findVectorPartner(
    std::vector<int>& chain,
    int partner)
{
    std::vector<int>::iterator it = chain.begin();

    while (it != chain.end())
    {
        if (*it == partner)
            return it;

        ++it;
    }

    return chain.end();
}

std::deque<int>::iterator
PmergeMe::findDequePartner(
    std::deque<int>& chain,
    int partner)
{
    std::deque<int>::iterator it = chain.begin();

    while (it != chain.end())
    {
        if (*it == partner)
            return it;

        ++it;
    }

    return chain.end();
}

void PmergeMe::sortVector(std::vector<int>& container)
{
    if (container.size() <= 1)
        return;

    std::vector<VectorPair> pairs;

    bool hasStraggler = (container.size() % 2 != 0);
    int straggler = 0;

    std::size_t pairEnd = container.size();

    if (hasStraggler)
    {
        straggler = container.back();
        --pairEnd;
    }

    for (std::size_t i = 0; i < pairEnd; i += 2)
    {
        VectorPair pair;

        if (container[i] < container[i + 1])
        {
            pair.small = container[i];
            pair.large = container[i + 1];
        }
        else
        {
            pair.small = container[i + 1];
            pair.large = container[i];
        }

        pairs.push_back(pair);
    }

    std::vector<int> largeChain;

    for (std::size_t i = 0; i < pairs.size(); ++i)
        largeChain.push_back(pairs[i].large);

    sortVector(largeChain);

    std::vector<VectorPair> orderedPairs;

    for (std::size_t i = 0; i < largeChain.size(); ++i)
    {
        for (std::size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].large == largeChain[i])
            {
                orderedPairs.push_back(pairs[j]);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    std::vector<int> mainChain = largeChain;

    if (!orderedPairs.empty())
    {
        mainChain.insert(
            mainChain.begin(),
            orderedPairs[0].small);
    }

    std::vector<std::size_t> order =
        generateInsertionOrder(orderedPairs.size());

    for (std::size_t i = 0; i < order.size(); ++i)
    {
        std::size_t index = order[i];

        int value = orderedPairs[index].small;
        int partner = orderedPairs[index].large;

        std::vector<int>::iterator partnerPosition =
            findVectorPartner(mainChain, partner);

        std::vector<int>::iterator insertPosition =
            std::lower_bound(
                mainChain.begin(),
                partnerPosition,
                value);

        mainChain.insert(insertPosition, value);
    }

    if (hasStraggler)
    {
        std::vector<int>::iterator insertPosition =
            std::lower_bound(
                mainChain.begin(),
                mainChain.end(),
                straggler);

        mainChain.insert(insertPosition, straggler);
    }

    container = mainChain;
}

void PmergeMe::sortDeque(std::deque<int>& container)
{
    if (container.size() <= 1)
        return;

    std::deque<DequePair> pairs;

    bool hasStraggler = (container.size() % 2 != 0);
    int straggler = 0;

    std::size_t pairEnd = container.size();

    if (hasStraggler)
    {
        straggler = container.back();
        --pairEnd;
    }

    for (std::size_t i = 0; i < pairEnd; i += 2)
    {
        DequePair pair;

        if (container[i] < container[i + 1])
        {
            pair.small = container[i];
            pair.large = container[i + 1];
        }
        else
        {
            pair.small = container[i + 1];
            pair.large = container[i];
        }

        pairs.push_back(pair);
    }

    std::deque<int> largeChain;

    for (std::size_t i = 0; i < pairs.size(); ++i)
        largeChain.push_back(pairs[i].large);

    sortDeque(largeChain);

    std::deque<DequePair> orderedPairs;

    for (std::size_t i = 0; i < largeChain.size(); ++i)
    {
        for (std::size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].large == largeChain[i])
            {
                orderedPairs.push_back(pairs[j]);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    std::deque<int> mainChain = largeChain;

    if (!orderedPairs.empty())
    {
        mainChain.insert(
            mainChain.begin(),
            orderedPairs[0].small);
    }

    std::vector<std::size_t> order =
        generateInsertionOrder(orderedPairs.size());

    for (std::size_t i = 0; i < order.size(); ++i)
    {
        std::size_t index = order[i];

        int value = orderedPairs[index].small;
        int partner = orderedPairs[index].large;

        std::deque<int>::iterator partnerPosition =
            findDequePartner(mainChain, partner);

        std::deque<int>::iterator insertPosition =
            std::lower_bound(
                mainChain.begin(),
                partnerPosition,
                value);

        mainChain.insert(insertPosition, value);
    }

    if (hasStraggler)
    {
        std::deque<int>::iterator insertPosition =
            std::lower_bound(
                mainChain.begin(),
                mainChain.end(),
                straggler);

        mainChain.insert(insertPosition, straggler);
    }

    container = mainChain;
}

void PmergeMe::execute()
{
    std::cout << "Before: ";

    for (std::size_t i = 0; i < _vector.size(); ++i)
    {
        std::cout << _vector[i];

        if (i + 1 < _vector.size())
            std::cout << " ";
    }

    std::cout << std::endl;

    clock_t vectorStart = std::clock();

    sortVector(_vector);

    clock_t vectorEnd = std::clock();

    clock_t dequeStart = std::clock();

    sortDeque(_deque);

    clock_t dequeEnd = std::clock();

    std::cout << "After:  ";

    for (std::size_t i = 0; i < _vector.size(); ++i)
    {
        std::cout << _vector[i];

        if (i + 1 < _vector.size())
            std::cout << " ";
    }

    std::cout << std::endl;

    double vectorTime =
        static_cast<double>(vectorEnd - vectorStart)
        / CLOCKS_PER_SEC
        * 1000000.0;

    double dequeTime =
        static_cast<double>(dequeEnd - dequeStart)
        / CLOCKS_PER_SEC
        * 1000000.0;

    std::cout
        << "Time to process a range of "
        << _vector.size()
        << " elements with std::vector : "
        << vectorTime
        << " us"
        << std::endl;

    std::cout
        << "Time to process a range of "
        << _deque.size()
        << " elements with std::deque  : "
        << dequeTime
        << " us"
        << std::endl;
}