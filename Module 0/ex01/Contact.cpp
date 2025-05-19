#include "Contact.hpp"

void Contact::setInfo() {
    std::cout << "First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
}

std::string truncate(std::string str) {
    return (str.length() > 10 ? str.substr(0, 9) + "." : str);
}

void Contact::showShortInfo(int index) {
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << truncate(firstName) << "|"
              << std::setw(10) << truncate(lastName)  << "|"
              << std::setw(10) << truncate(nickname)  << "|"
              << "\n";
}

void Contact::showFullInfo() {
    std::cout   <<	"First Name: "		<<	firstName		<<	"\n"
                <<	"Last Name: "		<<	lastName		<<	"\n"
                <<	"Nickname: "		<<	nickname		<<	"\n"
				<<	"Phone Number: "	<<	phoneNumber		<<	"\n"
				<<	"Darkest Secret: "	<<	darkestSecret	<<	"\n";
}
