#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _mapping(other._mapping) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        _mapping = other._mapping;
    return *this;
}

void BitcoinExchange::getDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file)
        throw std::runtime_error("The database file could not be open");
    
    std::string line;
    getline(file, line);
    while (getline(file, line)) {
        if (line.empty()) continue;

        std::size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            throw std::runtime_error("Error loading database");
        
        std::string date = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1, line.length());

        if (!parseDate(date))
            throw std::runtime_error("Error validating dates in database");

        _mapping[date] = std::strtof(rateStr.c_str(), NULL);
    }
}

void BitcoinExchange::processMap(const std::string &filename) const {
    std::ifstream file(filename.c_str());
    if (!file)
        throw std::runtime_error("The user file could not be open");
    
    std::string line;
    getline(file, line);

    while (getline(file, line)) {
        if (line.find("|") == std::string::npos)
        {
            std::cout << "Bad input" << std::endl;
            continue;
        }
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        std::string date = line.substr(0, 10);
        char *end;
        double value = std::strtod(line.substr(11, line.length()).c_str(), &end);
        if (*end != '\0')
        {
            std::cout << "invalid value!" << std::endl;
            continue;
        }
        if (!parseDate(date))
        {
            std::cout << "invalid date!" << std::endl;
            continue;
        }
        if (value < 0)
            std::cout << "Error: not a positive number." << std::endl;
        else if (value > 1000)
            std::cout << "Error: too large number" << std::endl;
        else {
            float rate = getRate(date);
            std::cout << date << " => " << value << " = " << rate * value << std::endl;
        }
    }
}

bool BitcoinExchange::parseDate(const std::string &date) const {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12) return false;
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        monthDays[1] = 29;

    if (day < 1 || day > monthDays[month - 1]) return false;

    return true;
}

float BitcoinExchange::getRate(const std::string &date) const {
    std::map<std::string, float>::const_iterator it = _mapping.lower_bound(date);

    if (it == _mapping.end() || it->first != date) {
        if (it == _mapping.begin())
            throw std::runtime_error("There is no values for the input data");
        --it;
    }
    return it->second;
}
