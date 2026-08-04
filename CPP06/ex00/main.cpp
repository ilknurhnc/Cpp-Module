#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        std::cerr << "\n=== Recommended Test Cases ===" << std::endl;
        std::cerr << "Char Literals   : ./convert 'a' | ./convert z" << std::endl;
        std::cerr << "Int Literals    : ./convert 0 | ./convert 42 | ./convert -42" << std::endl;
        std::cerr << "Float Literals  : ./convert 0.0f | ./convert 42.0f | ./convert -4.2f" << std::endl;
        std::cerr << "Double Literals : ./convert 0.0 | ./convert 42.0 | ./convert -4.2" << std::endl;
        std::cerr << "Pseudo Literals : ./convert nan | ./convert nanf | ./convert +inf | ./convert -inff" << std::endl;
        std::cerr << "Error Cases     : ./convert 42a | ./convert 1.0fxy | ./convert \"\"" << std::endl;
        return 1;
    }

    std::cout << "==========================================" << std::endl;
    std::cout << "  Input Literal : [" << argv[1] << "]" << std::endl;
    std::cout << "==========================================" << std::endl;

    ScalarConverter::convert(argv[1]);

    std::cout << "==========================================" << std::endl;

    return 0;
}