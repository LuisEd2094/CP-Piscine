#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact_class.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     index;
        
    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void    add(void);
        void    search(void);
        void    print_info(Contact contact);

        Contact get_contact(int index);
};
#endif