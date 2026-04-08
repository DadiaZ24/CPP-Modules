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

        static bool ftIsNan(const std::string &str);
        static bool ftIsInf(const std::string &str);

        static void printChar(const std::string &str, Type type);
        static void printInt(const std::string &str, Type type);
        static void printFloat(const std::string &str, Type type);
        static void printDouble(const std::string &str, Type type);

    public:
        static void convert(const std::string& literal);
};

#endif
