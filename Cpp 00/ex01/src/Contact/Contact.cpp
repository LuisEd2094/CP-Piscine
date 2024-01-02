#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact(void)
{
}
Contact::~Contact(void)
{
}
std::string Contact::get_input(std::string info)
{
    std::string str;

    str = "";
    while (str == "")
    {
        std::cout << "Enter " << info << " for your contact: ";
		get_new_input(str);
		if (std::cin.eof() == 1)
			PhoneBook::exit_program();
        if (info == "phone number")
        {
            if (!is_phone_number(str))
                str = "";
        }
    }
    return (str);
}


void Contact::create(void)
{
    std::string str;

    set_first_name(Contact::get_input("first name"));
    set_last_name(Contact::get_input("last name"));
    set_nick_name(Contact::get_input("nick name"));
    set_phone_number(Contact::get_input("phone number"));
    set_darkest_secret(Contact::get_input("darkest secret"));   
}

void    Contact::print_formatted_info(std::string prefix, std::string info)
{
    std::cout << prefix << info << std::endl;
}

void    Contact::print_info(void)

{
    print_formatted_info("First name: ", get_first_name());
    print_formatted_info("Last name: ", get_last_name());
    print_formatted_info("Nick name: ", get_nick_name());
    print_formatted_info("Phone number: ", get_phone_number());
    print_formatted_info("Darkest secret: ", get_darkest_secret());
}


void Contact::set_first_name(std::string str)
{
    first_name = str;
}

void Contact::set_last_name(std::string str)
{
    last_name = str;
}

void Contact::set_phone_number(std::string str)
{
    phone_number = str;
}

void Contact::set_nick_name(std::string str)
{
    nick_name = str;
}

void Contact::set_darkest_secret(std::string str)
{
    darkest_secret = str;
}

std::string Contact::get_first_name(void) const
{
    return (first_name);
}

std::string Contact::get_last_name(void) const
{
    return (last_name);
}

std::string Contact::get_phone_number(void) const
{
    return (phone_number);
}

std::string Contact::get_darkest_secret(void) const
{
    return (darkest_secret);
}

std::string Contact::get_nick_name(void) const
{
    return (nick_name);
}
