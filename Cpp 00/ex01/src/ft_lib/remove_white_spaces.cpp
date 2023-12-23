#include "ft_lib.hpp"

std::string remove_white_space(std::string str)
{

    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    if (start != std::string::npos) 
    {
        str = str.substr(start);
    }
    else 
        return ("");
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    if (end != std::string::npos)
    {
        str = str.substr(0, end + 1);
    }
    return (str);
}