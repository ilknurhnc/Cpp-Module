#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>

class ScalarConverter 
{
    private:
        ScalarConverter(); 
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);

        static void printChar(double d);
        static void printInt(double d);
        static void printFloat(double d);
        static void printDouble(double d);

    public:
        static void convert(const std::string& literal); 
};

#endif