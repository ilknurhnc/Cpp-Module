#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime> 
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm for " << this->target << " created." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm for " << this->target << " destroyed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target)
{
    std::cout << "RobotomyRequestForm for " << this->target << " copied." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    AForm::operator=(other);
    std::cout << "RobotomyRequestForm assigned." << std::endl;
    return *this;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "*DRILLING NOISES* VRRRR-ZZZZZZ-TICK-VRRRRRRR!" << std::endl;

    if (std::rand() % 2) 
        std::cout << this->target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed for " << this->target << "." << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    AForm::execute(executor);
}