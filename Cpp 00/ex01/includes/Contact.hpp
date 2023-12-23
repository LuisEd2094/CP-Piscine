#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include "ft_lib.hpp"

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name; 
        std::string phone_number;
        std::string darkest_secret;
        std::string get_input(std::string info);
        void        print_formatted_info(std::string prefix, std::string info);

    public:
        Contact(void);
        ~Contact(void);

        void    create(void);
        void    print_info(void);

        void    set_first_name(std::string str);
        void    set_last_name(std::string str);
        void    set_phone_number(std::string str);
        void    set_nick_name(std::string str);
        void    set_darkest_secret(std::string str);

        std::string	get_first_name(void) const;
        std::string	get_last_name(void) const;
        std::string	get_phone_number(void) const;
        std::string get_nick_name(void) const;
        std::string get_darkest_secret(void) const;
};
#endif