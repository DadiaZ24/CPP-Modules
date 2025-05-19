#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <limits>

class PhoneBook {
    private:
        Contact contacts[8];
        int totalContacts;
        int actualIndex;
    public:
        PhoneBook();
        void addContact();
        void searchContact();
};

#endif
