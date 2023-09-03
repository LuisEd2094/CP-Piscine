#include "PhoneBook_class.hpp"

PhoneBook::PhoneBook(void)
{
    this->index = 0;
    std::cout << \
        "Welcome to the Phone Book! You can store up to 8 contacts, but it's empty now!" \
        << std::endl;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "Closing! See you later!" << std::endl;
}

void PhoneBook::add(void)
{
    Contact new_contact;

    if (this->index > 7)
        std::cout << "You have reached the book limit, you will overwrite " << \
        this->contacts[0].get_first_name() << std::endl;
    new_contact.create();
    this->contacts[this->index % 8] = new_contact;
    this->index++;
}

void    PhoneBook::print_info(Contact contact)
{
    std::cout << "First Name : " << contact.get_first_name() << std::endl;
    std::cout << "Last Name : " << contact.get_last_name() << std::endl;
    std::cout << "Phone Number : " << contact.get_phone_number() << std::endl;
}

Contact PhoneBook::get_contact(int index)
{
    return (this->contacts[index]);
}