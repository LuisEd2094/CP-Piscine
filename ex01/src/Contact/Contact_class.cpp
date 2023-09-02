#include "Contact_class.hpp"

Contact::Contact(void)
{
}
Contact::~Contact(void)
{
}

void Contact::create(void)
{
    std::string str;

    std::cout << "Enter first name for your contact: ";
    std::getline(std::cin, str);
    this->set_first_name(str);

    std::cout << "Enter last name for your contact: ";
    std::getline(std::cin, str);
    this->set_last_name(str);

    std::cout << "Enter phone number for your contact: ";
    std::getline(std::cin, str);
    this->set_phone_number(str);
    
}

void Contact::set_first_name(std::string str)
{
    this->first_name = str;
}

void Contact::set_last_name(std::string str)
{
    this->last_name = str;
}

void Contact::set_phone_number(std::string str)
{
    this->phone_number = str;
}

std::string Contact::get_first_name(void) const
{
    return (this->first_name);
}

std::string Contact::get_last_name(void) const
{
    return (this->last_name);
}

std::string Contact::get_phone_number(void) const
{
    return (this->phone_number);
}
