#include "ft_lib.hpp"

bool is_only_numbers(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}