#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Functions.hpp"
#include <iostream>

int main(void)
{
	std::srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        std::cout << "--- Test " << i + 1 << " ---" << std::endl;
        Base *ptr = generate();
        std::cout << "Pointer: ";
        identify(ptr);
        std::cout << "Reference: ";
        identify(*ptr);
        delete ptr;
    }
    return 0;
}
