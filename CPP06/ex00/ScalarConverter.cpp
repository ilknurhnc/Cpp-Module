#include "ScalarConverter.hpp"
#include <cstdlib> 
#include <iomanip>
#include <cmath>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

void ScalarConverter::printChar(double d)
{
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    
    if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min()) {
        std::cout << "impossible" << std::endl;
        return;
    }

    char c = static_cast<char>(d);
    if (c < 32 || c > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;
}

void ScalarConverter::printInt(double d)
{
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d))
    {
        std::cout << "impossible" << std::endl;
        return;
    }

    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
    {
        std::cout << "impossible" << std::endl;
        return;
    }

    std::cout << static_cast<int>(d) << std::endl;
}

void ScalarConverter::printFloat(double d)
{
    std::cout << "float: ";
    
    if (d > std::numeric_limits<float>::max() && !std::isinf(d))
    {
        std::cout << "+inf" << "f" << std::endl;
        return;
    }
    if (d < -std::numeric_limits<float>::max() && !std::isinf(d))
    {
        std::cout << "-inf" << "f" << std::endl;
        return;
    }
    float f = static_cast<float>(d);
    std::cout << std::fixed << std::setprecision(1);

    if (std::isnan(d))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(d) && d > 0)
        std::cout << "+inf" << "f" << std::endl;
    else if (std::isinf(d) && d < 0) 
        std::cout << "-inf" << "f" << std::endl;
    else
        std::cout << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1);

    if (std::isnan(d))
        std::cout << "nan" << std::endl;
    else if (std::isinf(d) && d > 0)
        std::cout << "+inf" << std::endl;
    else if (std::isinf(d) && d < 0)
        std::cout << "-inf" << std::endl;
    else
        std::cout << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    char* endptr = NULL;
    double d = 0.0;
    bool is_char_literal_processed = false;

    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
    {
        d = static_cast<double>(literal[1]);
        is_char_literal_processed = true;
    }
    else if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
    {
        d = static_cast<double>(literal[0]);
        is_char_literal_processed = true;
    }

    if (is_char_literal_processed)
        endptr = const_cast<char*>(literal.c_str() + literal.length());
    else
        d = std::strtod(literal.c_str(), &endptr);

    if (*endptr != '\0')
    {
        if (*endptr == 'f' && *(endptr + 1) == '\0') {

        }
        else if (std::isnan(d) || std::isinf(d)){}
        else if (is_char_literal_processed){}
        else {
             std::cerr << "Error: Invalid literal format (trailing chars or non-numeric)." << std::endl;
             return;
        }
    }
    
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}