#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern& obj);
        Intern& operator=(const Intern& obj);

        AForm* makeForm(std::string form_name, std::string target);
};

#endif