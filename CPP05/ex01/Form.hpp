#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string name;
    bool is_signed;
    const int grade_to_sign;
    const int grade_to_execute;

public:

    class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    
    // Parametreli Kurucu (is_signed başlangıçta false olmalı)
    Form(const std::string& name, int sign_grade, int exec_grade);
    ~Form();
    Form(const Form& other);
    Form& operator=(const Form& other);

    const std::string& getName() const;
    bool getSignedStatus() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif