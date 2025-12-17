#include "Bureaucrat.hpp"
#include <iostream>

void test_bureaucrat(const std::string& name, int grade)
{
    std::cout << "\n--- Testing Bureaucrat: " << name << " Grade: " << grade << " ---" << std::endl;
    try
    {
        Bureaucrat b(name, grade);
        std::cout << b << std::endl;

        if (b.getGrade() > 1)
        {
            b.incrementGrade();
            std::cout << b << std::endl;
        }

        if (b.getGrade() < 150)
        {
            b.decrementGrade();
            std::cout << b << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
}

int main()
{
    test_bureaucrat("Arthur", 42);
    test_bureaucrat("TooHighGuy", 0);
    test_bureaucrat("TooLowGuy", 151);

    try
    {
        Bureaucrat b("Maximal", 1);
        std::cout << "\n--- Testing GradeTooHigh on Increment ---" << std::endl;
        std::cout << b << std::endl;
        b.incrementGrade(); // İstisna fırlatmalı
    }
    catch (std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Minimal", 150);
        std::cout << "\n--- Testing GradeTooLow on Decrement ---" << std::endl;
        std::cout << b << std::endl;
        b.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
