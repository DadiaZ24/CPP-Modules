#include <iostream>
#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"

int main()
{
    std::cout << "=== Form & Bureaucrat Tests ===" << std::endl;

    try
    {
        Bureaucrat bob("Bob", 9);
        Bureaucrat alice("Alice", 80);
        Bureaucrat tom("Tom", 150);

        std::cout << "\nCreating valid forms..." << std::endl;
        Form taxForm("Tax Declaration", 75, 100);
        Form topSecret("Top Secret Document", 10, 5);

        std::cout << "\n--- Form info ---" << std::endl;
        std::cout << taxForm << std::endl;
        std::cout << topSecret << std::endl;

        std::cout << "\n--- Signing tests ---" << std::endl;
        taxForm.beSigned(bob);
        taxForm.beSigned(alice);
        topSecret.beSigned(bob);
        topSecret.beSigned(alice);

        std::cout << "\n--- Final forms state ---" << std::endl;
        std::cout << taxForm << std::endl;
        std::cout << topSecret << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing invalid forms ===" << std::endl;

    try {
        Form invalidHigh("InvalidHigh", 0, 50);
    } catch (std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Form invalidLow("InvalidLow", 200, 50);
    } catch (std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== End of tests ===" << std::endl;
    return 0;
}
