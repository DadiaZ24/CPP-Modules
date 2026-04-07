#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::cout << "=== VALUE FOUND ===" << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "=== VALUE NOT FOUND ===" << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 100);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "=== FIRST OCURRENCE ===" << std::endl;
    std::vector<int> dup;
    dup.push_back(5);
    dup.push_back(5);
    dup.push_back(3);
    dup.push_back(3);
    dup.push_back(4);
    dup.push_back(4);
    try {
        std::vector<int>::iterator it = easyfind(dup, 5);
        std::cout << "Found: " << *it << std::endl;
        std::cout << "Index: " << std::distance(dup.begin(), it) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(dup, 3);
        std::cout << "Found: " << *it << std::endl;
        std::cout << "Index: " << std::distance(dup.begin(), it) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(dup, 4);
        std::cout << "Found: " << *it << std::endl;
        std::cout << "Index: " << std::distance(dup.begin(), it) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
