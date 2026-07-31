#include "Contact.hpp"

Contact::Contact() {
}

void Contact::setContact(std::string fName, std::string lName, std::string nName, std::string pNum, std::string dSecret) {
    this->firstName = fName;
    this->lastName = lName;
    this->nickname = nName;
    this->phoneNumber = pNum;
    this->darkestSecret = dSecret;
}

std::string Contact::getFirstName() const {
    return this->firstName;
}

std::string Contact::getLastName() const {
    return this->lastName;
}

std::string Contact::getNickname() const {
    return this->nickname;
}

std::string Contact::getPhoneNumber() const {
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return this->darkestSecret;
}
