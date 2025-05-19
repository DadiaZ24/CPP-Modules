#include "PhoneBook.hpp"

int main() {
    PhoneBook phoneBook;
    std::string cmd;

    while (1) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, cmd);

        if (std::cin.eof()) break;

        if (cmd == "ADD") {
            phoneBook.addContact();
        } else if (cmd == "SEARCH") {
            phoneBook.searchContact();
        } else if (cmd == "EXIT") {
            break;
        } else {
            std::cout << "Invalid cmd.\n";
        }
    }

    return 0;
}
