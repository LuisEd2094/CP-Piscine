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
        static std::size_t m_dot_pos;
        static std::string m_sub_str_int ;
        static std::string m_str;
        static std::string  m_literal;
        static bool        m_has_f;
        static bool        m_has_sign;
        static int         m_int;
        static unsigned char m_char;
        static float       m_float;
        static double      m_double;
        static e_type      m_type;
        static e_type      check_type();
        static bool is_valid_number();
        static bool is_int();
        static bool is_char();
        static bool is_float();
        static bool is_double();
        static bool is_literal();


        static void print_char(std::string str);
        static void print_int(std::string str);
        static void print_float(std::string str);
        static void print_double(std::string str);
        static void literal_case();


        
        ScalarConverter();
        ScalarConverter(const ScalarConverter & other);
        ScalarConverter& operator=(const ScalarConverter& rhs);

    public:
        ~ScalarConverter();

        
        static void convert(char *str);
};



typedef bool (*type_function)();

struct type_info {
    e_type type;
    type_function f;
};


#endif
