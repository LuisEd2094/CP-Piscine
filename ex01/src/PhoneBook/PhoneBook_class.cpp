#include "PhoneBook_class.hpp"

PhoneBook:PhoneBook(void)
{
    this->index = 0;
    std::cout << \
        "Welcome to the Phone Book! You can store up to 8 contacts, but it's empty now!" \
        << std:endl;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "Closing! See you later!" << std::endl;
}

Contact PhoneBook::get_contact(int index)
{
    if (index > 7)
        return std::nullopt;
    else
        return (this->contacts[index]);
}