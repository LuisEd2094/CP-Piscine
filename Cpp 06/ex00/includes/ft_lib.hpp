#ifndef FT_LIB_HPP
# define FT_LIB_HPP

# include <iostream>
# include <cstdlib>

std::string remove_white_space(std::string str);
bool        check_if_only_zeros(std::string &str);
bool        is_phone_number(const std::string &str);

#endif