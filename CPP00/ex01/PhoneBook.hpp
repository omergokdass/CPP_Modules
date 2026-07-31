#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook {
private:
    Contact contacts[8];
    int     count;
    int     oldestIndex;

    std::string formatColumn(std::string str) const;
    void        displayContact(int index) const;

public:
    PhoneBook();
    void addContact();
    void searchContacts() const;
};

#endif
