#ifndef FT_LIB_HPP
# define FT_LIB_HPP

# include <iostream>
# include <cstdlib>

std::string remove_white_space(std::string str);
bool        check_if_only_zeros(const std::string &str);
bool        is_only_numbers(const std::string &str);

#endif