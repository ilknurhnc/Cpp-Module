#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;

    protected:
        virtual void executeAction() const = 0;

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

        class FormNotSignedException : public std::exception
        {
            public:
                const char *what() const throw();
        };
    
        AForm(const std::string& name, int sign, int exec);
        virtual ~AForm();
        AForm(const AForm& obj);
        AForm& operator=(const AForm& obj);

        const std::string& getName() const;
        bool getSignedStatus() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& b);
        void execute(const Bureaucrat& executor) const;

};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif