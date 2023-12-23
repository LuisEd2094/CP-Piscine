#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->index = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::exit_program(void)
{
    std::cout << "Closing! See you later!" << std::endl;
    std::exit(EXIT_SUCCESS);
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

int PhoneBook::get_index_to_replace(void)
{
    std::string input = "";
    int contact_index;
    int check_index; 

    std::cout << "You have reached the book limit" << std::endl;
    this->print_ui();
    while (input == "")
    {
        std::cout << "Select an index for the contact you want to replace" << std::endl;
        get_new_input(input);
        if (std::cin.eof() == 1)
            this->exit_program();
        if (check_if_only_zeros(input))
            contact_index = 0;
        else
            contact_index = std::atoi(input.c_str());
        if (contact_index > 0 && contact_index  < 9)
        {
            input = "";
            std::cout << "You are about to remove" << this->contacts[contact_index].get_first_name() << std::endl;
            std::cout << "Enter the same index to confirm" << std::endl;
            get_new_input(input);
            if (std::cin.eof() == 1)
                this->exit_program();
            check_index = std::atoi(input.c_str());
            if (check_index == contact_index)
                break;
        }
        input = ""; 
    }
    return (contact_index - 1);
}

void PhoneBook::add(void)
{
    Contact new_contact;
    int contact_index;

    if (this->index == 8)
    {
        contact_index = this->get_index_to_replace();
    }
    else
        contact_index = this->index;
    new_contact.create();
    this->contacts[contact_index] = new_contact;
    std::cout << new_contact.get_first_name() << " added to PhoneBook!" << std::endl;
    if (this->index < 8)
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

void PhoneBook::print_ui(void)
{
    int i = 0;
    Contact contact;
    std::string str;

    if (!this->contacts)
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
        this->print_ui();
        std::cout << "Select a contact index: ";
        get_new_input(str);
		if (std::cin.eof() == 1)
			this->exit_program();
        index = atoi(str.c_str()) - 1;
        if (index >= 0 && index < this->index)
        {
            this->contacts[index].print_info();
            break;
        }
    }

}