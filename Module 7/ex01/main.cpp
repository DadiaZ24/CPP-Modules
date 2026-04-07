#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const &elem)
{
    std::cout << elem << " " << std::endl;
}

template <typename T>
void increment(T &elem)
{
    elem++;
}

void toUpper(char &c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 32;
}

// --- Tests ---

int main( void )
{
    std::cout << "=== int array (print) ===" << std::endl;
    int ints[] = {1, 2, 3, 4, 5};
    iter(ints, 5, print<int>);

    std::cout << "=== int array (increment) ===" << std::endl;
    iter(ints, 5, increment<int>);
    iter(ints, 5, print<int>);

    std::cout << "=== double array (print) ===" << std::endl;
    double doubles[] = {1.1, 2.2, 3.3};
    iter(doubles, 3, print<double>);

    std::cout << "=== string array (print) ===" << std::endl;
    std::string strs[] = {"hello", "world", "42"};
    iter(strs, 3, print<std::string>);

    std::cout << "=== const int array (print) ===" << std::endl;
    int const consts[] = {10, 20, 30};
    iter(consts, 3, print<int>);

    std::cout << "=== char array (makeUpper) ===" << std::endl;
    char chars[] = {'h', 'e', 'l', 'l', 'o'};
    iter(chars, 5, toUpper);
    iter(chars, 5, print<char>);

    return 0;
}
