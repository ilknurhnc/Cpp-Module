#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp" 
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void) {
    std::srand(std::time(NULL));

    Intern intern_factory;
    Bureaucrat boss("Boss (Grade 1)", 1);
    
    AForm* form1 = NULL;
    AForm* form2 = NULL;
    AForm* form3 = NULL;
    AForm* form_invalid = NULL;

    std::cout << "=================== INTERN FABRİKASI TESTİ ===================" << std::endl;
    
    try
    {
        std::cout << "\n--- 1.1: Robotomy Talebi ---" << std::endl;
        form1 = intern_factory.makeForm("robotomy request", "Bender");

        std::cout << "\n--- 1.2: Presidential Pardon Talebi ---" << std::endl;
        form2 = intern_factory.makeForm("presidential pardon", "Ford Prefect");
        
        std::cout << "\n--- 1.3: Shrubbery Creation Talebi ---" << std::endl;
        form3 = intern_factory.makeForm("shrubbery creation", "Garden");
        
        std::cout << "\n--- 2. YANLIŞ İSİM TESTİ ---" << std::endl;
        form_invalid = intern_factory.makeForm("yanlis form adi", "Mars");
        if (form_invalid == NULL) {
            std::cout << "Başarılı: Geçersiz form adı NULL döndürdü." << std::endl;
        }

        std::cout << "\n--- 3. BAŞARILI YÜRÜTME TESTİ ---" << std::endl;
        
        if (form1) {
            boss.signForm(*form1);
            boss.executeForm(*form1);
        }
        if (form2) {
            boss.signForm(*form2);
            boss.executeForm(*form2);
        }
        
    }
    catch (std::exception& e)
    {
        std::cerr << "\n[MAIN CATCH] Genel Istisna Yakalandi: " << e.what() << std::endl;
    }
    
    std::cout << "\n=================== TEMİZLİK BAŞLADI ===================" << std::endl;
    delete form1;
    delete form2;
    delete form3;

    std::cout << "=================== TEST SONU ===================" << std::endl;
    return 0;
}
