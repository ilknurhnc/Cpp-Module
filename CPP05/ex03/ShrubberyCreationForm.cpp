#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

#define SHR_SIGN 145
#define SHR_EXEC 137

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", SHR_SIGN, SHR_EXEC), target(target)
{
    std::cout << "ShrubberyCreationForm for " << this->target << " created." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm for " << this->target << " destroyed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
    std::cout << "ShrubberyCreationForm for " << this->target << " copied." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    AForm::operator=(other);
    std::cout << "ShrubberyCreationForm assigned." << std::endl;
    return *this;
}

void ShrubberyCreationForm::executeAction() const
{
    std::string filename = this->target + "_shrubbery";
    std::ofstream ofs(filename.c_str()); 

    if (!ofs.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << " for writing (Shrubbery creation failed)." << std::endl;
        return;
    }

    ofs << "       /\\      " << std::endl;
    ofs << "      /\\*\\     " << std::endl;
    ofs << "     /\\o\\*\\    " << std::endl;
    ofs << "    /\\/\\/\\/\\   " << std::endl;
    ofs << "   /\\*\\o\\/\\*\\  " << std::endl;
    ofs << "  /\\/\\*\\/\\/\\/\\ " << std::endl;
    ofs << "       ||      " << std::endl;
    ofs << "  Target: " << this->target << std::endl;

    ofs.close();
    std::cout << "Shrubbery creation successful! File: " << filename << " created." << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    AForm::execute(executor);
}
