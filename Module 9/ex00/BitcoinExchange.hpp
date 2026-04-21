#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <cstdlib>

class BitcoinExchange {
    private:
        std::map<std::string, float> _mapping;

        bool parseDate(const std::string &date) const;
        float getRate(const std::string& date) const;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void getDatabase(const std::string &filename);
        void processMap(const std::string &filename) const;
};

#endif
