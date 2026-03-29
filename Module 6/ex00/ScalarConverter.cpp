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

bool ScalarConverter::ftIsNan(double value) {
    return value != value;
}

bool ScalarConverter::ftIsInf(double value) {
    return (value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::max());
}

void ScalarConverter::printChar(double value, bool impossible) {
    std::cout << "char: ";
    if (impossible || ftIsNan(value) || ftIsInf(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value, bool impossible) {
    std::cout << "int: ";
    if (impossible || ftIsNan(value) || ftIsInf(value) || value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value, bool isPseudo) {
    std::cout << "float: ";
    float floatValue = static_cast<float>(value);
    if (isPseudo || ftIsNan(value) || ftIsInf(value)) {
        if (ftIsNan(value))
            std::cout << "nanf" << std::endl;
        else if (value > 0)
            std::cout << "+inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
    }
    else {
        std::cout << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value, bool isPseudo) {
	std::cout << "double: ";
	if (isPseudo || ftIsNan(value) || ftIsInf(value)) {
		if (ftIsNan(value))
			std::cout << "nan" << std::endl;
		else if (value > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else {
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
	}
}

void ScalarConverter::convert(const std::string &str) {
    Type type = detectType(str);
    double value = 0;
    bool impossible = false;

    switch (type)
    {
        case CHAR:
        {
            value = static_cast<double>(str[0]);
            break;
        }
        
        case INT:
        {
            char *end;
            long val = std::strtol(str.c_str(), &end, 10);
            if (*end != '\0' || val > INT_MAX || val < INT_MIN)
                impossible = true;
            value = static_cast<double>(val);
            break;
        }
        
        case FLOAT:
        {
            std::string floatString = str.substr(0, str.length() - 1);
            char *end;
            value = std::strtod(floatString.c_str(), &end);
            if (*end != '\0')
                impossible = true;
            break;
        }

        case DOUBLE:
        {
            char *end;
            value = std::strtod(str.c_str(), &end);
            if (*end != '\0')
                impossible = true;
            break;
        }

        case PSEUDO:
        {
            if (str == "nan" || str == "nanf")
                value = std::numeric_limits<double>::quiet_NaN();
            else if (str == "+inf" || str == "+inff"
				|| str == "inf" || str == "inff")
				value = std::numeric_limits<double>::infinity();
			else
				value = -std::numeric_limits<double>::infinity();
			break;
		}
 
		case INVALID:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
	}
 
	bool pseudo = (type == PSEUDO);
	printChar(value, impossible);
	printInt(value, impossible);
	printFloat(value, pseudo);
	printDouble(value, pseudo);
}
