#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T &element) {
    std::cout << element << " ";
}

template <typename T>
void increment(T &element) {
    element++;
}

void toUpperPrefix(std::string &str) {
    str = "42_" + str;
}

int main(void) {
    std::cout << "=== TEST 1: Integer Array (Non-Const) ===" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    size_t num_len = sizeof(numbers) / sizeof(numbers[0]);

    std::cout << "Original: ";
    ::iter(numbers, num_len, printElement<int>);
    std::cout << std::endl;

    std::cout << "Incrementing elements..." << std::endl;
    ::iter(numbers, num_len, increment<int>);

    std::cout << "Modified: ";
    ::iter(numbers, num_len, printElement<int>);
    std::cout << "\n\n";

    std::cout << "=== TEST 2: String Array ===" << std::endl;
    std::string words[] = {"cpp", "module", "templates"};
    size_t word_len = sizeof(words) / sizeof(words[0]);

    std::cout << "Original: ";
    ::iter(words, word_len, printElement<std::string>);
    std::cout << std::endl;

    ::iter(words, word_len, toUpperPrefix);

    std::cout << "Modified: ";
    ::iter(words, word_len, printElement<std::string>);
    std::cout << "\n\n";

    std::cout << "=== TEST 3: Const Integer Array (Read-Only) ===" << std::endl;
    const int const_numbers[] = {10, 20, 30};
    size_t const_len = sizeof(const_numbers) / sizeof(const_numbers[0]);

    std::cout << "Const Elements: ";

    ::iter(const_numbers, const_len, printElement<int>);
    std::cout << std::endl;

    return 0;
}