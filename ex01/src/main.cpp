#include "Contact_class.hpp"
#include "PhoneBook_class.hpp"

int main(void)
{
    Contact new_contact;
    PhoneBook phonebook;

    phonebook.add();
    new_contact= phonebook.get_contact(0);

    phonebook.print_info(phonebook.get_contact(0));

    
}