#include "includes/Bureaucrat.hpp"

int main() {
    std::cout << "== Basic operations ===" << std::endl;
    try {
        Bureaucrat ObiWan("ObiWan Kenobi", 2);
        std::cout << ObiWan << std::endl;
        ObiWan.incrementGrade();
        std::cout << "after increment -> " << ObiWan << std::endl;
        ObiWan.incrementGrade();
        std::cout << "after increment again -> " << ObiWan << std::endl;

    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid constructions ===\n";
    try
    {
        Bureaucrat DarthVader("DarthVader", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << "DarthVader construction failed: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat Luke("Luke", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << "Luke construction failed: " << e.what() << std::endl;
    }

    std::cout << "\n=== Decrement to too low ===\n";
    try
    {
        Bureaucrat BB8("BB8", 149);
        std::cout << BB8 << std::endl;
        BB8.decrementGrade();
        std::cout << "after decrement: " << BB8 << std::endl;
        BB8.decrementGrade();
        std::cout << "after second decrement: " << BB8 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
