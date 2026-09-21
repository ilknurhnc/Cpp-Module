#include "MutantStack.hpp"

#include <iostream>
#include <stack>
#include <list>

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

    std::cout << "\n----- STD::STACK COPY TEST -----" << std::endl;

    std::stack<int> s(mstack);

    std::cout << "Copied stack top: " << s.top() << std::endl;

    std::cout << "Copied stack size: " << s.size() << std::endl;


    std::cout << "\n----- LIST COMPARISON TEST -----" << std::endl;

    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    return 0;
}