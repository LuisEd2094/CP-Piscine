#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <sstream>
# include <string>

# include "ft_lib.hpp"



class ScalarConverter
{
    private:
        std::size_t m_dot_pos;
        std::string m_sub_str_int;
        bool        m_has_f;
        bool        m_has_sign;
        bool is_valid_number(const std::string& str);
        bool is_int(const std::string& str);
        bool is_char(const std::string str);
        bool isFloat(const std::string str);

    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter & other);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        
        void convert(char *str);
};

#endif