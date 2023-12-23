#include "ft_lib.hpp"

bool        check_if_only_zeros(std::string &str)
{
	std::string::iterator it;
	
	for (it = str.begin(); it < str.end(); it++)
    {
        if (*it != '0')
            return (0);
    } 
	return (1);
}
