#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Invalid usage. Use ./btc <input file>" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    try {
        btc.getDatabase("data.csv");
        btc.processMap(av[1]);
    } catch (std::exception &e) {
        std::cerr << "An error as occurred: " << e.what();
        return 1;
    }
    return 0;
}
