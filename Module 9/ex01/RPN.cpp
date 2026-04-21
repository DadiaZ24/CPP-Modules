#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other) : _stack(other._stack) {}
RPN::~RPN() {}
RPN &RPN::operator=(const RPN &other) {
    if (this != &other)
        _stack = other._stack;
    return *this;
}

int RPN::run(const std::string &operation) {
    while (!_stack.empty())
        _stack.pop();
    
    std::istringstream iss(operation);
    std::string token;

    while (iss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
        {
            _stack.push(token[0] - '0');
        }
        else if (token == "+" || token == "-" || token == "/" || token == "*")
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Invalid number of digits or operators (you need to have less 1 operator than digits).\n");
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            _stack.push(makeOperation(a, b, token[0]));
        }
        else
            throw std::runtime_error("Invalid operation\n");
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Invalid operation\n");
    return _stack.top();
}

int RPN::makeOperation(int a, int b, char mathOperator) {
    if (mathOperator == '+')
        return a + b;
    else if (mathOperator == '-')
        return a - b;
    else if (mathOperator == '*')
        return a * b;
    else if (mathOperator == '/')
    {
        if (b == 0)
            throw std::runtime_error("Can't divide by 0\n");
        else
            return a / b;
    }
    else
        throw std::runtime_error("Invalid operation!\n");
    return 0;
}
