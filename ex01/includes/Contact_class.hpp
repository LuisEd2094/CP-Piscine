#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string phone_number;
    public:
        Contact(void);
        ~Contact(void);

        void    create(void);

        void    set_first_name(std::string str);
        void    set_last_name(std::string str);
        void    set_phone_number(std::string str);

        std::string	get_first_name(void) const;
        std::string	get_last_name(void) const;
        std::string	get_phone_number(void) const;
};
#endif