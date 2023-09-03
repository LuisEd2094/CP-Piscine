#include "Contact_class.hpp"
#include "PhoneBook_class.hpp"

int main(void)
{
    Contact new_contact;
    PhoneBook phonebook;

    phonebook.add();
    new_contact= phonebook.get_contact(0);
    phonebook.print_info(phonebook.get_contact(0));




    for (int i = 0; i < 8; i++)
        phonebook.add();
    new_contact= phonebook.get_contact(0);

    phonebook.print_info(phonebook.get_contact(0));

    std::cout << 9 % 8 << std::endl;
}