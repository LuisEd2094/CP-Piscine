#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <climits>
# include "ft_lib.hpp"


class ScalarConverter
{
    private:
        bool isInt(const std::string  str);

    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter & other);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        
        void convert(char *str);
};

#endif