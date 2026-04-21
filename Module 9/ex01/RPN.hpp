#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>

class RPN {
    private:
        std::stack<int> _stack;
        int makeOperation(int a, int b, char mathOperator);
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        int run(const std::string &operation);
};

#endif