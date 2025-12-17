#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base *generate(void)
{
    int random = rand() % 3; 

    switch (random) {
        case 0:
            std::cout << "DEBUG: Generating A class instance." << std::endl;
            return new A();
        case 1:
            std::cout << "DEBUG: Generating B class instance." << std::endl;
            return new B();
        case 2:
            std::cout << "DEBUG: Generating C class instance." << std::endl;
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p)
{
    if (p == NULL)
    {
        std::cout << "Identified type (Pointer): NULL" << std::endl;
        return;
    }

    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "Identified type (Pointer): A" << std::endl;

    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Identified type (Pointer): B" << std::endl;

    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Identified type (Pointer): C" << std::endl;
    else
        std::cout << "Identified type (Pointer): Unknown" << std::endl;
}

void identify(Base& p)
{
    std::cout << "Identified type (Reference): ";

    try
    {
        (void)dynamic_cast<A&>(p); 
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::exception& e){}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::exception& e) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (const std::exception& e) {}
    std::cout << "Unknown" << std::endl;
}
