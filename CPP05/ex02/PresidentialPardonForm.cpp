#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm for " << this->target << " created." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm for " << this->target << " destroyed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), target(other.target)
{
    std::cout << "PresidentialPardonForm for " << this->target << " copied." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    AForm::operator=(other);
    std::cout << "PresidentialPardonForm assigned." << std::endl;
    return *this;
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    AForm::execute(executor);
}