#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        const std::string target;
        void executeAction() const;

    public:
        PresidentialPardonForm(const std::string& target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

        void execute(const Bureaucrat& executor) const;
};

#endif