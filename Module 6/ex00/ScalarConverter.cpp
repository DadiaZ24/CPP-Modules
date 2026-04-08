#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {(void)other; return *this;}
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string &str) {
    return (str.length() == 1 && !std::isdigit(str[0]));
}

bool ScalarConverter::isInt(const std::string &str) {
    size_t i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    if (i == str.length())
        return false;
    while (i < str.length())
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string &str) {
    if (str.empty() || str[str.length() - 1] != 'f')
        return false;
    std::string strTrim = str.substr(0, str.length() - 1);
    if (strTrim.find('.') == std::string::npos)
        return false;
    size_t i = 0;
    bool dotFound = false;

    if (strTrim[i] == '+' || strTrim[i] == '-')
        i++;
    if (i == strTrim.length())
        return false;
    while (i < strTrim.length())
    {
        if (strTrim[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (!std::isdigit(strTrim[i]))
            return false;
        i++;
    }
    return dotFound;
}

bool ScalarConverter::isDouble(const std::string &str) {
    if (str.find('.') == std::string::npos)
        return false;
    size_t i = 0;
    bool dotFound = false;

    if (str[i] == '+' || str[i] == '-')
        i++;
    if (i == str.length())
        return false;
    while (i < str.length())
    {
        if (str[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return dotFound;
}

bool ScalarConverter::isPseudo(const std::string &str) {
    return (str == "nan" || str == "+inf" || str == "-inf" || str == "nanf" || str == "+inff" || str == "-inff"
		|| str == "inf" || str == "inff");
}

ScalarConverter::Type ScalarConverter::detectType(const std::string &str) {
    if (str.empty())
        return INVALID;
    if (isPseudo(str))
        return PSEUDO;
    if (isChar(str))
        return CHAR;
    if (isInt(str))
        return INT;
    if (isFloat(str))
        return FLOAT;
    if (isDouble(str))
        return DOUBLE;
    return INVALID;
}

bool ScalarConverter::ftIsNan(const std::string &str) {
    return (str == "nan" || str == "nanf");
}

bool ScalarConverter::ftIsInf(const std::string &str) {
    return (str == "inf" || str == "+inf" || str == "-inf"
         || str == "inff" || str == "+inff" || str == "-inff");
}

void ScalarConverter::printChar(const std::string &str, Type type) {
    std::cout << "char: ";
    if (ftIsNan(str) || ftIsInf(str)) {
        std::cout << "impossible" << std::endl;
        return;
    }
    long val;
    if (type == CHAR)
        val = static_cast<long>(str[0]);
    else if (type == INT)
        val = std::strtol(str.c_str(), NULL, 10);
    else if (type == FLOAT) {
        std::string fs = str.substr(0, str.length() - 1);
        val = static_cast<long>(std::strtof(fs.c_str(), NULL));
    }
    else
        val = static_cast<long>(std::strtod(str.c_str(), NULL));

    if (val < 0 || val > 127) {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (!std::isprint(static_cast<int>(val)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
}

void ScalarConverter::printInt(const std::string &str, Type type) {
    std::cout << "int: ";
    if (ftIsNan(str) || ftIsInf(str)) {
        std::cout << "impossible" << std::endl;
        return;
    }
    long val;
    if (type == CHAR)
        val = static_cast<long>(str[0]);
    else if (type == INT) {
        char *end;
        val = std::strtol(str.c_str(), &end, 10);
        if (*end != '\0' || val > INT_MAX || val < INT_MIN) {
            std::cout << "impossible" << std::endl;
            return;
        }
    }
    else if (type == FLOAT) {
        std::string fs = str.substr(0, str.length() - 1);
        float fval = std::strtof(fs.c_str(), NULL);
        if (fval > static_cast<float>(INT_MAX) || fval < static_cast<float>(INT_MIN)) {
            std::cout << "impossible" << std::endl;
            return;
        }
        val = static_cast<long>(fval);
    }
    else {
        double dval = std::strtod(str.c_str(), NULL);
        if (dval > static_cast<double>(INT_MAX) || dval < static_cast<double>(INT_MIN)) {
            std::cout << "impossible" << std::endl;
            return;
        }
        val = static_cast<long>(dval);
    }
    std::cout << static_cast<int>(val) << std::endl;
}

void ScalarConverter::printFloat(const std::string &str, Type type) {
    std::cout << "float: ";
    if (ftIsNan(str)) {
        std::cout << "nanf" << std::endl;
        return;
    }
    if (ftIsInf(str)) {
        std::cout << (str[0] == '-' ? "-inff" : "+inff") << std::endl;
        return;
    }
    float val;
    if (type == CHAR)
        val = static_cast<float>(str[0]);
    else if (type == INT)
        val = static_cast<float>(std::strtol(str.c_str(), NULL, 10));
    else if (type == FLOAT) {
        std::string fs = str.substr(0, str.length() - 1);
        val = std::strtof(fs.c_str(), NULL);
    }
    else
        val = static_cast<float>(std::strtod(str.c_str(), NULL));
    std::cout << std::fixed << std::setprecision(1) << val << "f" << std::endl;
}

void ScalarConverter::printDouble(const std::string &str, Type type) {
    std::cout << "double: ";
    if (ftIsNan(str)) {
        std::cout << "nan" << std::endl;
        return;
    }
    if (ftIsInf(str)) {
        std::cout << (str[0] == '-' ? "-inf" : "+inf") << std::endl;
        return;
    }
    double val;
    if (type == CHAR)
        val = static_cast<double>(str[0]);
    else if (type == INT)
        val = static_cast<double>(std::strtol(str.c_str(), NULL, 10));
    else if (type == FLOAT) {
        std::string fs = str.substr(0, str.length() - 1);
        val = static_cast<double>(std::strtof(fs.c_str(), NULL));
    }
    else
        val = std::strtod(str.c_str(), NULL);
    std::cout << std::fixed << std::setprecision(1) << val << std::endl;
}

void ScalarConverter::convert(const std::string &str) {
    Type type = detectType(str);

    if (type == INVALID) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    printChar(str, type);
    printInt(str, type);
    printFloat(str, type);
    printDouble(str, type);
}
