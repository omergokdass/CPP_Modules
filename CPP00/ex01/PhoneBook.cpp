#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->count = 0;
    this->oldestIndex = 0;
}

std::string PhoneBook::formatColumn(std::string str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

static std::string getInput(std::string prompt) {
    std::string input = "";
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            return "";
        if (!input.empty())
            break;
        std::cout << "Alan bos birakilamaz! Lutfen tekrar giriniz.\n";
    }
    return input;
}

void PhoneBook::addContact() {
    std::string fName = getInput("First Name: ");
    if (fName.empty()) return;
    
    std::string lName = getInput("Last Name: ");
    if (lName.empty()) return;

    std::string nName = getInput("Nickname: ");
    if (nName.empty()) return;

    std::string pNum = getInput("Phone Number: ");
    if (pNum.empty()) return;

    std::string dSecret = getInput("Darkest Secret: ");
    if (dSecret.empty()) return;

    this->contacts[this->oldestIndex].setContact(fName, lName, nName, pNum, dSecret);
    this->oldestIndex = (this->oldestIndex + 1) % 8;
    if (this->count < 8)
        this->count++;
    std::cout << "Kisi basariyla eklendi!\n";
}

void PhoneBook::displayContact(int index) const {
    std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::searchContacts() const {
    if (this->count == 0) {
        std::cout << "Rehber bos! Once ADD komutu ile kisi ekleyiniz.\n";
        return;
    }

    std::cout << "---------------------------------------------\n";
    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname"
              << "|\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < this->count; i++) {
        std::cout << "|" << std::setw(10) << i
                  << "|" << std::setw(10) << formatColumn(this->contacts[i].getFirstName())
                  << "|" << std::setw(10) << formatColumn(this->contacts[i].getLastName())
                  << "|" << std::setw(10) << formatColumn(this->contacts[i].getNickname())
                  << "|\n";
    }
    std::cout << "---------------------------------------------\n";

    std::string input;
    std::cout << "Detaylarini gormek istediginiz kisinin indeksini giriniz (0 - " << (this->count - 1) << "): ";
    if (!std::getline(std::cin, input))
        return;

    if (input.length() == 1 && input[0] >= '0' && input[0] < '0' + this->count) {
        int index = input[0] - '0';
        displayContact(index);
    } else {
        std::cout << "Gecersiz indeks!\n";
    }
}
