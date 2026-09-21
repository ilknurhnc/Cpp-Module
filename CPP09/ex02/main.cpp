#include "PmergeMe.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    PmergeMe sorter;

    if (!sorter.parseInput(argc, argv))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    sorter.execute();

    return 0;
}