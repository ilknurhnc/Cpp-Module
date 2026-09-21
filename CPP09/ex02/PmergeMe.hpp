#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <cstddef>

class PmergeMe
{
private:
    struct VectorPair
    {
        int small;
        int large;
    };

    struct DequePair
    {
        int small;
        int large;
    };

    std::vector<int> _vector;
    std::deque<int>  _deque;

    bool parseNumber(const std::string& str, int& number) const;

    void sortVector(std::vector<int>& container);
    void sortDeque(std::deque<int>& container);

    std::vector<std::size_t>
    generateInsertionOrder(std::size_t size) const;

    std::vector<int>::iterator
    findVectorPartner(std::vector<int>& chain, int partner);

    std::deque<int>::iterator
    findDequePartner(std::deque<int>& chain, int partner);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    bool parseInput(int argc, char **argv);
    void execute();
};

#endif