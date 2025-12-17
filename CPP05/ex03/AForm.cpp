#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& n, int sign_g, int exec_g)
    : name(n), is_signed(false), grade_to_sign(sign_g), grade_to_execute(exec_g)
{
    if (sign_g < 1 || exec_g < 1)
        throw AForm::GradeTooHighException();
    if (sign_g > 150 || exec_g > 150)
        throw AForm::GradeTooLowException();
    std::cout << "AForm " << this->name << " base created." << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm " << this->name << " base destroyed." << std::endl;
}

AForm::AForm(const AForm& other)
    : name(other.name), is_signed(other.is_signed),
      grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
    std::cout << "AForm " << this->name << " base copied." << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other) {
        this->is_signed = other.is_signed;
        std::cout << "AForm " << this->name << " base assigned." << std::endl;
    }
    return *this;
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (this->is_signed) {
        std::cout << this->name << " is already signed." << std::endl;
        return;
    }
    if (b.getGrade() > this->grade_to_sign)
        throw AForm::GradeTooLowException();
    
    this->is_signed = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
    if (!this->is_signed)
        throw AForm::FormNotSignedException();
    
    if (executor.getGrade() > this->grade_to_execute)
        throw AForm::GradeTooLowException();
    
    this->executeAction();
}

const std::string& AForm::getName() const {
    return this->name;
}

bool AForm::getSignedStatus() const {
    return this->is_signed;
}

int AForm::getGradeToSign() const {
    return this->grade_to_sign;
}

int AForm::getGradeToExecute() const {
    return this->grade_to_execute;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << "AForm: " << obj.getName() 
       << ", Signed: " << (obj.getSignedStatus() ? "Yes" : "No") 
       << ", Grade to Sign: " << obj.getGradeToSign()
       << ", Grade to Execute: " << obj.getGradeToExecute()
       << ".";
    return os;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "AForm exception: Grade is too high (must be 1 or greater).";
}
const char *AForm::GradeTooLowException::what() const throw() {
    return "AForm exception: Grade is too low (must be 150 or lower).";
}
const char *AForm::FormNotSignedException::what() const throw() {
    return "AForm exception: Form is not signed.";
}
