#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

//COLORS:
#define RESET "\033[0m"
#define CLASS_CALL "\033[35m"
#define TEST "\033[36m"
#define SOUND "\033[33m"
#define TITLE "\033[32m"

#include <string>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <limits>
#include <iomanip>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

        enum Type {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            PSEUDO,
            INVALID
        };

        static Type detectType(const std::string &str);
        static bool isChar(const std::string &str);
        static bool isInt(const std::string &str);
        static bool isFloat(const std::string &str);
        static bool isDouble(const std::string &str);
        static bool isPseudo(const std::string &str);

        static void printChar(double value, bool impossible);
        static void printInt(double value, bool impossible);
        static void printFloat(double value, bool isPseudo);
        static void printDouble(double value, bool isPseudo);

        static bool ftIsNan(double value);
        static bool ftIsInf(double value);
    public:
        static void convert(const std::string& literal);
};

#endif