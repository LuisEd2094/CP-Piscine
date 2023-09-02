#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

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
        void    print(Contact contact);

        Contact get_contact(int index);
};
#endif