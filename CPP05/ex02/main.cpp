#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Tek ve ana test fonksiyonu
int main(void) {
    std::srand(std::time(NULL));

    AForm* form1 = NULL;
    AForm* form2 = NULL;
    AForm* form3 = NULL;
    
    Bureaucrat* boss = NULL;
    Bureaucrat* low = NULL;
    
    std::cout << "=================== BÜROKRASİ TESTİ BAŞLADI ===================" << std::endl;

    try {
        // 1. NESNE OLUŞTURMA
        boss = new Bureaucrat("Boss (Grade 1)", 1);
        low = new Bureaucrat("Lowbie (Grade 150)", 150);
        
        form1 = new PresidentialPardonForm("Zaphod'a Teslim Edilecek Kisi"); // Sign: 25, Exec: 5
        form2 = new RobotomyRequestForm("Kedi Mimar");                   // Sign: 72, Exec: 45
        form3 = new ShrubberyCreationForm("Tatil Evi");                  // Sign: 145, Exec: 137

        std::cout << "\n--- 2. DURUM: BAŞARILI İMZA VE YÜRÜTME (BOSS) ---" << std::endl;
        
        // Boss, her şeyi imzalayıp yürütebilir.
        std::cout << *form1 << std::endl;
        boss->signForm(*form1);
        boss->executeForm(*form1); 

        std::cout << *form2 << std::endl;
        boss->signForm(*form2);
        boss->executeForm(*form2); 

        std::cout << *form3 << std::endl;
        boss->signForm(*form3);
        boss->executeForm(*form3); 
        
        // --- Lowbie'nin yetkisizlik hatasını görmek için imzasız form deniyoruz ---
        std::cout << "\n--- 3. DURUM: YETKİSİZ İMZA DENEMESİ (LOWBIE) ---" << std::endl;
        PresidentialPardonForm form_p_test("Lowbie_Test_Hedefi"); // Yeni, imzasız form
        
        // Lowbie (150), Sign 25 gerektiren formu imzalamaya çalışır -> HATA BEKLENİYOR
        low->signForm(form_p_test); 

        std::cout << "\n--- 4. DURUM: İMZALI AMA YETKİSİZ YÜRÜTME ---" << std::endl;
        // Robotomy Formu (Exec 45) imzalı. Lowbie'nin (150) yetkisi yetmez.
        low->executeForm(*form2); 

    } catch (std::exception& e) {
        // Kurucu hataları vb. buraya düşer
        std::cerr << "\n[MAIN CATCH] Genel Istisna Yakalandi: " << e.what() << std::endl;
    }

    // 5. TEMİZLİK
    std::cout << "\n=================== TEMİZLİK BAŞLADI ===================" << std::endl;
    delete boss;
    delete low;
    delete form1;
    delete form2;
    delete form3;
    
    std::cout << "=================== TEST SONU ===================" << std::endl;
    return 0;
}