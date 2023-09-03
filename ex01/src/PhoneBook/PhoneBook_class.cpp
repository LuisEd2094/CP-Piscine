#include "PhoneBook_class.hpp"

PhoneBook::PhoneBook(void)
{
    this->index = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::exit_message(void)
{
    std::cout << "Closing! See you later!" << std::endl;
}

void PhoneBook::instructions(void)
{
    std::cout   << "Type ADD to create and add a new contact. " << std::endl\
                << "Type SEARCH to see a list of contacts" \
                << "and then type it's index to get the contact information." << std::endl \
                << "Type EXIT to close program." << std::endl;

}

void PhoneBook::welcome_message(void)
{
    std::cout << \
        "Welcome to the Phone Book! You can store up to 8 contacts, but it's empty now!" \
        << std::endl;
}

void PhoneBook::add(void)
{
    Contact new_contact;

    if (this->index > 7)
        std::cout << "You have reached the book limit, you will overwrite " << \
        this->contacts[0].get_first_name() << std::endl;
    new_contact.create();
    this->contacts[this->index % 8] = new_contact;
    std::cout << new_contact.get_first_name() << " added to PhoneBook!" << std::endl;
    this->index++;
}

std::string PhoneBook::get_spaces(int size)
{
    std::string str;

    while (size-- > 0)
        str.append(" ");
    return(str);
}

std::string PhoneBook::resize_str(std::string str)
{
    str.resize(10);
    str[9] = '.';
    return (str);
}


void PhoneBook::print_formatted_value(std::string str)
{
    int str_size = str.size();
    
    std::cout << "|";
    if (str_size <= 10)
        std::cout << get_spaces(10 - str_size) << str;
    else
        std::cout << resize_str(str); 

}

void PhoneBook::print_ui(Contact *contacts)
{
    int i = 0;
    Contact contact;
    std::string str;

    if (!contacts)
        return;
    std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
    while (i < this->index)
    {
        contact = this->contacts[i];
        std::cout << "|" << get_spaces(9) << i + 1;
        print_formatted_value(contact.get_first_name());
        print_formatted_value(contact.get_last_name());
        print_formatted_value(contact.get_nick_name());
        std::cout << "|" << std::endl;
        i++;
    }
	std::cout << " ------------------------------------------- " << std::endl;
}

void    PhoneBook::search(void)
{

    std::string str;
    int index;

    if (this->index == 0)
    {
        std::cout << "Phonebook is empty!" << std::endl;
        return; 
    }
    while (1)
    {
        this->print_ui(this->contacts);
        std::cout << "Select a contact index: ";
        std::getline(std::cin, str);
        str = remove_white_space(str);
        index = atoi(str.c_str()) - 1;
        if (index >= 0 && index < this->index)
        {
            this->contacts[index].print_info();
            break;
        }
    }

}