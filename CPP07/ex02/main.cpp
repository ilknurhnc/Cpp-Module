#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    std::cout << "=== 1. PARAMETERIZED CONSTRUCTOR & SIZE TEST ===" << std::endl;
    Array<int> intArray(5);
    std::cout << "intArray size: " << intArray.size() << std::endl;
    
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = (i + 1) * 10;
    }

    std::cout << "intArray elements: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "=== 2. COPY CONSTRUCTOR & DEEP COPY TEST ===" << std::endl;
    Array<int> copyArray = intArray;
    intArray[0] = 999;

    std::cout << "Original intArray[0] (Modified): " << intArray[0] << std::endl;
    std::cout << "Copy copyArray[0] (Should be unchanged): " << copyArray[0] << std::endl;
    std::cout << "\n";

    std::cout << "=== 3. TEMPLATE TYPE TEST (STRING ARRAY) ===" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "42";
    strArray[1] = "Network";
    strArray[2] = "C++ Module 07";

    for (unsigned int i = 0; i < strArray.size(); i++) {
        std::cout << "strArray[" << i << "]: " << strArray[i] << std::endl;
    }
    std::cout << "\n";

    std::cout << "=== 4. OUT OF BOUNDS (EXCEPTION) TEST ===" << std::endl;
    try {
        std::cout << "Accessing out of bounds index (index 10)..." << std::endl;
        intArray[10] = 42;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Accessing negative index (index -1)..." << std::endl;
        intArray[-1] = 42;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}