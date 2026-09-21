#include "BitcoinExchange.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _database = other._database;

    return *this;
}

BitcoinExchange::~BitcoinExchange(){}

std::string BitcoinExchange::trim(const std::string& str) const
{
    std::string::size_type start = 0;

    while (start < str.length() && std::isspace(static_cast<unsigned char>(str[start])))
        ++start;

    std::string::size_type end = str.length();

    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
        --end;

    return str.substr(start, end - start);
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (std::size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;

        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int year;
    int month;
    int day;
    char dash1;
    char dash2;

    std::istringstream iss(date);

    if (!(iss >> year >> dash1 >> month >> dash2 >> day))
        return false;

    if (dash1 != '-' || dash2 != '-')
        return false;

    if (year < 0)
        return false;

    if (month < 1 || month > 12)
        return false;

    static const int daysInMonth[12] =
    {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    int maxDay = daysInMonth[month - 1];

    bool leapYear =
        (year % 4 == 0 && year % 100 != 0)
        || (year % 400 == 0);

    if (month == 2 && leapYear)
        maxDay = 29;

    if (day < 1 || day > maxDay)
        return false;

    return true;
}

bool BitcoinExchange::parseValue(
    const std::string& str,
    double& value) const
{
    std::string cleaned = trim(str);

    if (cleaned.empty())
        return false;

    std::istringstream iss(cleaned);

    if (!(iss >> value))
        return false;

    char extra;

    if (iss >> extra)
        return false;

    return true;
}

bool BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open database." << std::endl;
        return false;
    }

    std::string line;

    if (!std::getline(file, line))
    {
        std::cerr << "Error: empty database." << std::endl;
        return false;
    }

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::string::size_type comma = line.find(',');

        if (comma == std::string::npos)
            continue;

        std::string date = trim(line.substr(0, comma));
        std::string rateString = trim(line.substr(comma + 1));

        if (!isValidDate(date))
            continue;

        double rate;

        if (!parseValue(rateString, rate))
            continue;

        if (rate < 0)
            continue;

        _database[date] = rate;
    }

    if (_database.empty())
    {
        std::cerr << "Error: database contains no valid data."
                  << std::endl;
        return false;
    }

    return true;
}

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it;

    it = _database.lower_bound(date);

    if (it != _database.end() && it->first == date)
        return it->second;

    if (it == _database.begin())
        return -1.0;

    --it;

    return it->second;
}

bool BitcoinExchange::processInput(const std::string& filename) const
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }

    std::string line;

    if (!std::getline(file, line))
    {
        std::cerr << "Error: empty file." << std::endl;
        return false;
    }

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::string::size_type pipe = line.find('|');

        if (pipe == std::string::npos || line.find('|', pipe + 1) != std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipe));
        std::string valueString = trim(line.substr(pipe + 1));

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double value;

        if (!parseValue(valueString, value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        double rate = getExchangeRate(date);

        if (rate < 0)
        {
            std::cerr << "Error: no exchange rate available for => " << date << std::endl;
            continue;
        }

        std::cout << date
                  << " => "
                  << value
                  << " = "
                  << value * rate
                  << std::endl;
    }

    return true;
}