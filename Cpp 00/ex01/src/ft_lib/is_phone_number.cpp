#include "ft_lib.hpp"

bool is_phone_number(const std::string &str)
{
    return str.find_first_not_of("0123456789-") == std::string::npos;
}