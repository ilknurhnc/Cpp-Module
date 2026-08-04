#include "ScalarConverter.hpp"
#include <cstdlib> 
#include <iomanip>
#include <cmath>
#include <cctype>

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

static bool isNan(double d)
{
    return d != d;
}

static bool isInf(double d)
{
    return d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity();
}

void ScalarConverter::printChar(double d)
{
    std::cout << "char: ";
    if (isNan(d) || isInf(d))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    
    if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min()) {
        std::cout << "impossible" << std::endl;
        return;
    }

    char c = static_cast<char>(d);
    if (!std::isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;
}

void ScalarConverter::printInt(double d)
{
    std::cout << "int: ";
    if (isNan(d) || isInf(d))
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

    if (isNan(d))
    {
        std::cout << "nanf" << std::endl;
        return;
    }
    if (isInf(d))
    {
        if (d > 0)
            std::cout << "+inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
        return;
    }

    if (d > std::numeric_limits<float>::max())
    {
        std::cout << "+inff" << std::endl;
        return;
    }
    if (d < -std::numeric_limits<float>::max())
    {
        std::cout << "-inff" << std::endl;
        return;
    }

    float f = static_cast<float>(d);
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1);

    if (isNan(d))
        std::cout << "nan" << std::endl;
    else if (isInf(d) && d > 0)
        std::cout << "+inf" << std::endl;
    else if (isInf(d) && d < 0)
        std::cout << "-inf" << std::endl;
    else
        std::cout << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    if (literal.empty())
    {
        std::cerr << "Error: Empty literal." << std::endl;
        return;
    }

    double d = 0.0;
    bool parsed = false;

    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
    {
        d = static_cast<double>(literal[1]);
        parsed = true;
    }
    else if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
    {
        d = static_cast<double>(literal[0]);
        parsed = true;
    }

    if (!parsed)
    {
        char* endptr = NULL;
        d = std::strtod(literal.c_str(), &endptr);

        bool isValidEnd = (*endptr == '\0') || (*endptr == 'f' && *(endptr + 1) == '\0');

        if (!isValidEnd && !isNan(d) && !isInf(d))
        {
            std::cerr << "Error: Invalid literal format." << std::endl;
            return;
        }
    }

    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}