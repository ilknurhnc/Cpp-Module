#include "Harl.hpp"

void Harl::debug() {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my burger!" << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]\nAdding extra bacon costs more money..." << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]\nI think I deserve some extra bacon for free." << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levelArray[] = {"DEBUG","INFO","WARNING","ERROR"};
    void (Harl::*functions[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error }; //“bu pointer, MyClass’ın bir üye fonksiyonunu tutuyor” demek.

    int i;
    for (i = 0; i < 4; i++)
    {
        if (levelArray[i]==level)
            break;
    }

switch (i)
{
    case 0:
     (this->*functions[0])();
    case 1:
     (this->*functions[1])();
    case 2:
     (this->*functions[2])();
    case 3:
     (this->*functions[3])();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]\n";
        break;
}
}