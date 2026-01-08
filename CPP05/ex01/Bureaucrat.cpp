#include "Bureaucrat.hpp"
#include "Form.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat exception: Grade is too high (must be 1 or greater).";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat exception: Grade is too low (must be 150 or lower).";
}

Bureaucrat::Bureaucrat(const std::string& n, int g) : name(name), grade(grade)
{
    if (g < 1)
        throw Bureaucrat::GradeTooHighException();
    if (g > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat " << this->name << " created with grade " << this->grade << "." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << this->name << " destroyed." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name), grade(obj.grade)
{
    std::cout << "Bureaucrat " << this->name << " copied." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    if (this != &obj)
    {
        this->grade = obj.grade;
        std::cout << "Bureaucrat " << this->name << " assigned grade " << this->grade << "." << std::endl;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
    std::cout << this->name << "'s grade incremented to " << this->grade << "." << std::endl;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade + 1 > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
    std::cout << this->name << "'s grade decremented to " << this->grade << "." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return os;
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << this->getName() << " couldn't sign " << form << " because " << e.what() << std::endl;
    }
}
