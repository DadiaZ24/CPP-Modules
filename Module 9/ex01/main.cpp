#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2)
    {
        std::cerr << "Invalid usage. Use ./RPN <operation>" << std::endl;
        return 1;
    }
    try {
        RPN obj;
        std::cout << obj.run(av[1]) << std::endl;
        return 0;
    } catch (std::exception &e) {
        std::cerr << "An error has occured: " << e.what();
        return 1;
    }
}
