#include "Contact.class.hpp"

Contact::Contact(void)
{
}
Contact::~Contact(void)
{
}

void Contact::set_first_name(std::string str)
{
    this->first_name = str;
}

void Contact::set_last_name(std::string str)
{
    this->last_name = str;
}

void Contact::set_nick_name(std::string str)
{
    this->nick_name = str;
}

void Contact::set_phone_number(std::string str)
{
    this->phone_number = str;
}

void Contact::set_darkest_secret(std::string str)
{
    this->darkest_secret = str;
}

std::string Contact::get_first_name(void) const
{
    return (this->first_name);
}

std::string Contact::get_last_name(void) const
{
    return (this->last_name);
}

std::string Contact::get_nick_name(void) const
{
    return (this->nick_name);
}

std::string Contact::get_phone_number(void) const
{
    return (this->phone_number);
}

std::string Contact::get_darkest_secret(void) const
{
    return (this->darkest_secret);
}