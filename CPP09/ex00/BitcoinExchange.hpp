#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
private:
    std::map<std::string, double> _database;

    bool        isValidDate(const std::string& date) const;
    bool        parseValue(const std::string& str, double& value) const;
    std::string trim(const std::string& str) const;
    double      getExchangeRate(const std::string& date) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    bool loadDatabase(const std::string& filename);
    bool processInput(const std::string& filename) const;
};

#endif