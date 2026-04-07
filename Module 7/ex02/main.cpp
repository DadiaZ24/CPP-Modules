#include <iostream>
#include <string>
#include "Array.hpp"

int main( void )
{
    std::cout << "=== Default construction ===" << std::endl;
    Array<int> empty;
    std::cout << "Size: " << empty.size() << std::endl;

    std::cout << "\n=== Construction with n=5 ===" << std::endl;
    Array<int> ints(5);
    for (unsigned int i = 0; i < ints.size(); i++)
        ints[i] = i * 10;
    for (unsigned int i = 0; i < ints.size(); i++)
        std::cout << "ints[" << i << "] = " << ints[i] << std::endl;

    std::cout << "\n=== Copy constructor ===" << std::endl;
    Array<int> copy(ints);
    copy[0] = 999;
    std::cout << "ints[0] after modifying copy: " << ints[0] << std::endl;
    std::cout << "copy[0]: " << copy[0] << std::endl;

    std::cout << "\n=== Assignment operator ===" << std::endl;
    Array<int> assigned;
    assigned = ints;
    assigned[1] = 888;
    std::cout << "ints[1] after modifying assigned: " << ints[1] << std::endl;
    std::cout << "assigned[1]: " << assigned[1] << std::endl;

    std::cout << "\n=== Out-of-bounds exception ===" << std::endl;
    try {
        std::cout << ints[10] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try {
        std::cout << empty[0] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught on empty: " << e.what() << std::endl;
    }

    std::cout << "\n=== String array ===" << std::endl;
    Array<std::string> strs(3);
    strs[0] = "hello";
    strs[1] = "world";
    strs[2] = "42";
    for (unsigned int i = 0; i < strs.size(); i++)
        std::cout << "strs[" << i << "] = " << strs[i] << std::endl;

    std::cout << "\n=== Const array access ===" << std::endl;
    Array<int> const constArr(ints);
    std::cout << "constArr[2] = " << constArr[2] << std::endl;
    try {
        std::cout << constArr[99] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception on const: " << e.what() << std::endl;
    }

    return 0;
}
