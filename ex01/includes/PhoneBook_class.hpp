#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact_class.hpp"
# include "ft_lib.hpp"
# include <stdlib.h> 


class PhoneBook
{
    private:
        Contact     contacts[8];
        int         index;
        std::string get_spaces(int size);
        void        print_formatted_value(std::string str);
        std::string resize_str(std::string str, int str_size);
        
    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void    exit_message(void);
        void    instructions(void);
        void    welcome_message(void);
        void    add(void);
        void    search(void);
        void    print_ui(Contact *contacts);

        Contact get_contact(int index);
};
#endif