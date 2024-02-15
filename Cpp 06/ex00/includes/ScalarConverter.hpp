/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:52:37 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:52:40 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <sstream>
# include <string>
# include <functional>
# include <cstring>
#include <iomanip>
#include <string>



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
        static std::size_t      _dot_pos;
        static std::string      _sub_str_int ;
        static std::string      _str;
        static std::string      _literal;
        static bool             _has_f;
        static bool             _has_sign;
        static int              _int;
        static unsigned char    _char;
        static float            _float;
        static double           _double;
        static e_type           _type;
        static e_type           check_type();
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
        static void char_case();
        static void float_case();


        static unsigned int get_presicion();

        
        ScalarConverter();
        ScalarConverter(const ScalarConverter & other);
        ScalarConverter& operator=(const ScalarConverter& rhs);
        ~ScalarConverter();


    public:
        static void convert(char *str);
};



typedef bool (*type_function)();

struct type_info {
    e_type type;
    type_function f;
};


#endif
