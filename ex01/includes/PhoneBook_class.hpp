#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact_class.hpp"
# include "ft_lib.hpp"
# include <stdlib.h> 


class PhoneBook
{
    private:
        Contact contacts[8];
        int     index;
        
    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void    exit_message(void);
        void    welcome_message(void);
        void    instructions(void);
        void    add(void);
        void    search(void);
        void    print_ui(Contact *contacts);
        void    print_info(Contact contact);

        Contact get_contact(int index);
};
#endif