#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years!" << std::endl;
}

void Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levelArray[] = {"DEBUG","INFO","WARNING","ERROR"};
    void (Harl::*functions[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error }; //“bu pointer, MyClass’ın bir üye fonksiyonunu tutuyor” demek.

    for (int i = 0; i < 4; i++)
    {
        if (levelArray[i]==level)
         (this->*functions[i])();
    }    
}