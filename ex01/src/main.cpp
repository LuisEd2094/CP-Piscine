#include "Contact_class.hpp"

int main(void)
{
    Contact new_contact;

    new_contact.set_first_name("Hello");

    std::string name = new_contact.get_first_name();

    std::cout << name << "HOLA" << std::endl;
    
}