#include "MutantStack.hpp"

#include <iostream>
#include <stack>

int main()
{
    MutantStack<int> mstack;

    std::cout << "----- STACK FUNCTIONS -----" << std::endl;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "\n----- ITERATOR TEST -----" << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "First element: " << *it << std::endl;

    ++it;
    std::cout << "After ++it: " << *it << std::endl;

    --it;
    std::cout << "After --it: " << *it << std::endl;

    std::cout << "\nAll elements:" << std::endl;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    return 0;
}