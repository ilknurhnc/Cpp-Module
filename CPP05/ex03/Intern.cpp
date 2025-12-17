#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
    std::cout << "Intern created. Ready to serve!" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destroyed. Hopefully learned something." << std::endl;
}

Intern::Intern(const Intern& other)
{
    (void)other;
    std::cout << "Intern copied." << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

AForm* Intern::makeForm(std::string form_name, std::string target) 
{
    const std::string valid_forms[] = { "shrubbery creation", "robotomy request", "presidential pardon"};
    
    AForm* new_form = NULL;
    int form_index = -1;

    for (int i = 0; i < 3; ++i)
    {
        if (form_name == valid_forms[i])
        {
            form_index = i;
            break;
        }
    }

    switch (form_index)
    {
        case 0:
            new_form = new ShrubberyCreationForm(target);
            break;
        case 1:
            new_form = new RobotomyRequestForm(target);
            break;
        case 2:
            new_form = new PresidentialPardonForm(target);
            break;
        default:
            std::cerr << "Intern error: Form name '" << form_name << "' is unknown or misspelled." << std::endl;
            return NULL;
    }
    
    std::cout << "Intern creates " << new_form->getName() << std::endl;
    return new_form;
}