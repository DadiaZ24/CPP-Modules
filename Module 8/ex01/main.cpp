#include <iostream>
#include "Span.hpp"

int main() {
    try {
        std::cout << "=== SUBJECT TESTS ===" << std::endl;
        Span sp = Span(5);
        try {
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            std::cout << "SHORTEST: " << sp.shortestSpan() << std::endl;
            std::cout << "LONGEST: " << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "=== ADD TO FULL SPAN ===" << std::endl;
        try {
            sp.addNumber(42);
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "=== NOT ENOUGH NUMBERS ===" << std::endl;
        Span empty(5);
        try {
            empty.shortestSpan();
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        empty.addNumber(5);
        try {
            empty.longestSpan();
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "=== ADD RANGE ===" << std::endl;
        std::vector<int> numbers;
        numbers.push_back(100);
        numbers.push_back(50);
        numbers.push_back(200);
        numbers.push_back(1);
        Span rangeSpan(10);
        rangeSpan.addRange(numbers.begin(), numbers.end());
        std::cout << "Shortest: " << rangeSpan.shortestSpan() << std::endl;
        std::cout << "Longest: " << rangeSpan.longestSpan() << std::endl;

        std::cout << "=== RANGE OVERFLOW" << std::endl;
        Span overflow(2);
        try {
            overflow.addRange(numbers.begin(), numbers.end());
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::cout << "=== 10000 numbers ===" << std::endl;
        Span big(10000);
        std::vector<int> bigVec;
        for (int i = 0; i < 10000; i++)
            bigVec.push_back(i);
        big.addRange(bigVec.begin(), bigVec.end());
        std::cout << "Shortest: " << big.shortestSpan() << std::endl;
        std::cout << "Longest: " << big.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "MAIN EXCEPTION!!!!! -> " << e.what() << std::endl;
    }

    return 0;
}