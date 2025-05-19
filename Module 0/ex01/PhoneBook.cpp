#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : totalContacts(0), actualIndex(0) {}

void PhoneBook::addContact() {
    std::cout << "Enter contact info: \n";
    contacts[actualIndex].setInfo();
    actualIndex = (actualIndex + 1) % 8;

    if (totalContacts < 8) totalContacts++;
    std::cout << "Contact added!\n";
}

void PhoneBook::searchContact() {
    if (totalContacts == 0) {
        std::cout << "\nERROR: There are no contacts available yet.\n\n";
        return;
    };
    std::cout << "Index | First Name | Last Name | Nickname\n";
    for (int i = 0; i < totalContacts; ++i) {
        contacts[i].showShortInfo(i);
    }
    std::cout << "Enter the index of the contact you want to view: ";
    int index;
    std::cin >> index;

    if (std::cin.fail() || index < 0 || index > totalContacts) {
        std::cin.clear();
        std::cout << "Invalid index. The index should be between 0 and " << totalContacts << "\n";
        return;
        
    }

    std::cin.ignore();
    contacts[index].showFullInfo();
}
