#include "Bureaucrat.hpp"
#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form exception: Grade is too high (must be 1 or greater).";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form exception: Grade is too low (must be 150 or lower).";
}

Form::Form(const std::string& name, int sign, int exec)
    : name(name), is_signed(false), grade_to_sign(sign), grade_to_execute(exec)
{
    if (sign < 1 || exec < 1)
        throw Form::GradeTooHighException();

    if (sign > 150 || exec > 150)
        throw Form::GradeTooLowException();

    std::cout << "Form " << this->name << " created." << std::endl;
}

Form::~Form()
{
    std::cout << "Form " << this->name << " destroyed." << std::endl;
}

Form::Form(const Form& obj)
    : name(obj.name), is_signed(obj.is_signed),
      grade_to_sign(obj.grade_to_sign), grade_to_execute(obj.grade_to_execute)
{
    std::cout << "Form " << this->name << " copied." << std::endl;
}

Form& Form::operator=(const Form& obj)
{
    if (this != &obj)
    {
        this->is_signed = obj.is_signed;
        std::cout << "Form " << this->name << " assigned (only signed status copied)." << std::endl;
    }
    return *this;
}

const std::string& Form::getName() const {
    return this->name;
}

bool Form::getSignedStatus() const {
    return this->is_signed;
}

int Form::getGradeToSign() const {
    return this->grade_to_sign;
}

int Form::getGradeToExecute() const {
    return this->grade_to_execute;
}

void Form::beSigned(const Bureaucrat& b)
{
    if (this->is_signed)
    {
        std::cout << this->name << " is already signed." << std::endl;
        return;
    }
    if (b.getGrade() > this->grade_to_sign)
        throw Form::GradeTooLowException();
    
    this->is_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << "Form: " << obj.getName() 
       << ", Signed: " << (obj.getSignedStatus() ? "Yes" : "No") 
       << ", Grade to Sign: " << obj.getGradeToSign()
       << ", Grade to Execute: " << obj.getGradeToExecute()
       << ".";
    return os;
}