#include "ft_lib.hpp"
#include "PhoneBook.hpp"

void get_new_input(std::string& str)
{
    std::getline(std::cin, str);
    str = remove_white_space(str);
    if (str == "EXIT")
        PhoneBook::exit_program();
}