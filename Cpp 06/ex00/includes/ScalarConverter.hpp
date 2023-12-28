#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <sstream>
# include <string>
# include <functional>


# include "ft_lib.hpp"

enum e_type {
    NONE,
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    LITERALS
};

class ScalarConverter
{
    private:
        std::size_t m_dot_pos;
        std::string m_sub_str_int;
        std::string m_str;
        bool        m_has_f;
        bool        m_has_sign;
        int         m_int;
        unsigned char m_char;
        float       m_float;
        double      m_double;
        e_type      m_type;
        e_type      check_type();
        bool is_valid_number();
        bool is_int();
        bool is_char();
        bool is_float();
        bool is_double();

    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter & other);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        
        void convert(char *str);
};



typedef bool (ScalarConverter::*type_function)();

struct type_info {
    e_type type;
    type_function f;
};


#endif