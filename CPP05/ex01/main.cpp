#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "\n--- Valid form construction ---" << std::endl;

    try
    {
        Form contract("Contract", 50, 25);
        std::cout << contract << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Invalid form grades ---" << std::endl;

    try
    {
        Form invalidHigh("InvalidHigh", 0, 50);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Form invalidLow("InvalidLow", 50, 151);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Successful signing ---" << std::endl;

    try
    {
        Bureaucrat manager("Manager", 40);
        Form contract("Contract", 50, 25);

        std::cout << contract << std::endl;
        manager.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Failed signing ---" << std::endl;

    try
    {
        Bureaucrat intern("Intern", 100);
        Form confidential("Confidential", 50, 25);

        intern.signForm(confidential);
        std::cout << confidential << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Exact required grade ---" << std::endl;

    try
    {
        Bureaucrat exact("Exact", 50);
        Form exactForm("ExactForm", 50, 25);

        exact.signForm(exactForm);
        std::cout << exactForm << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
