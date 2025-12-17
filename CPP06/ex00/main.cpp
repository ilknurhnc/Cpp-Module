#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        std::cerr << "--- Deneme Onerileri ---" << std::endl;
        std::cerr << "Basarili Sayisal: ./convert 42 | ./convert -4.2 | ./convert 0.0f" << std::endl;
        std::cerr << "Pseudo Literaller: ./convert nan | ./convert +inff | ./convert -inf" << std::endl;
        std::cerr << "Char Literalleri: ./convert 'A' | ./convert z" << std::endl;
        std::cerr << "Hata Durumlari:  ./convert 42a | ./convert 1.0fxy | ./convert 3000000000 | ./convert \"\"" << std::endl;
        return 1;
    }
    
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "--- Girdi Literal: [" << argv[1] << "] ---" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    ScalarConverter::convert(argv[1]);

    std::cout << "------------------------------------------" << std::endl;
    
    return 0;
}