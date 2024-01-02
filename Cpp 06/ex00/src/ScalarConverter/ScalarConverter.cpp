/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:52:50 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:52:54 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp" 

std::size_t ScalarConverter::_dot_pos = 0;
std::string ScalarConverter::_sub_str_int = "";
std::string ScalarConverter::_str = "";
std::string ScalarConverter::_literal = "";
bool ScalarConverter::_has_f = false;
bool ScalarConverter::_has_sign = false;
int ScalarConverter::_int = 0;
unsigned char ScalarConverter::_char = 0;
float ScalarConverter::_float = 0.0f;
double ScalarConverter::_double = 0.0;
e_type ScalarConverter::_type = NONE;

ScalarConverter::ScalarConverter(void){}
ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
        (void)src;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
    (void)rhs;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::is_int()
{
    std::string str_copy = _sub_str_int;
    long int strtol_value = 0;
    char *p_end;

    if (_dot_pos)
        _sub_str_int = _sub_str_int.substr(0, _sub_str_int.find('.'));
    if (check_if_only_zeros(str_copy))
        return (true);
    strtol_value = strtol(str_copy.c_str(), &p_end, 10);
    if (strtol_value > std::numeric_limits<int>::max())
        return (false);
    else if (strtol_value < std::numeric_limits<int>::min())
        return (false);
    return (strtol_value);
}

bool ScalarConverter::is_char()
{
    if (_str.length() > 1)
        return (false);
    std::cout << std::isprint(static_cast<unsigned char>(_str[0])) <<  std::endl;
    return (std::isprint(static_cast<unsigned char>(_str[0])));
}

bool ScalarConverter::is_double()
{
    return (_dot_pos && !(_has_f));
}

bool ScalarConverter::is_float()
{
    return(_has_f && _dot_pos);
}

bool ScalarConverter::is_valid_number()
{
    std::string str_copy = _str;
    std::ptrdiff_t dot_pos;

    for (std::string::iterator it = str_copy.begin(); it < str_copy.end(); it++)
    {
        if (it == str_copy.begin() && (*it == '+' || *it == '-'))
            _has_sign = 1;
        else if (*it == '.')
        {
            if (it == str_copy.end() - 1)
                return (false);
            else if (!_dot_pos)
            {
                dot_pos = std::distance(str_copy.begin(), it);
                if (_has_sign && dot_pos <= 1)
                    return (false);
                else if (dot_pos < 1)
                    return (false);
                else
                    _dot_pos = dot_pos;
            }
            else
                return (false);
        }
        else if (it == str_copy.end() - 1 && *it == 'f')
        {
            if (*it == 'f' && _dot_pos && *(it - 1) != '.')
            {
                _has_f = 1;
                return (true);
            }
            else
                return (false);
        }
        else if (!std::isdigit(*it) && str_copy.length() != 1 && std::isprint(*it))
            return (false);
    }
    return (true);
}


bool ScalarConverter::is_literal()
{
    std::string literals [] = {
        "-inff",
        "+inff", 
        "nanf",
        "-inf",
        "+inf",
        "nan",
    };
    for (size_t i = 0; i < sizeof(literals) / sizeof(literals[0]); ++i)
    {
        if (_str == literals[i])
        {
            _literal = literals[i];
            return true;
        }
    }
    return (false);

}


e_type ScalarConverter::check_type()
{
    type_info valid_types [] = {
        {CHAR, &ScalarConverter::is_char},
        {DOUBLE, &ScalarConverter::is_double},
        {FLOAT, &ScalarConverter::is_float},
        {INT, &ScalarConverter::is_int}
    };
    if (is_literal())
        return (LITERALS);
    if (!is_valid_number())
        return (NONE);
    for (size_t i = 0; i < sizeof(valid_types) / sizeof(valid_types[0]); ++i) {
        if ((valid_types[i].f)()) {
            return (valid_types[i].type);
        }
    }
    return (NONE);
}

void ScalarConverter::print_char(std::string str)
{
    std::cout << "char: " << str << std::endl;
}


void ScalarConverter::print_int(std::string str)
{
    std::cout << "int: " << str << std::endl;

}
void ScalarConverter::print_float(std::string str)
{
    std::cout << "float: " << str<< std::endl;

}
void ScalarConverter::print_double(std::string str)
{    
    std::cout << "double: " << str << std::endl;
}

void ScalarConverter::literal_case()
{
    std::string to_pass;

    print_char("imposible");
    print_int("imposible");
    print_float((_str.back() == 'f' && _str.back() - 1 == 'f') ? \
                _str : _str + "f");

    print_double((_str.back() == 'f' && _str.back() - 1 == 'f') ? \
                _str.substr(0, _str.size() - 1) : _str);
}

void ScalarConverter::convert(char *input)
{
    _str = static_cast<std::string>(input);
    _sub_str_int = _str;

    if (_str.empty())
    {
        std::cerr << "Empty argument" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    switch (check_type())
    {
        case LITERALS:
            literal_case();
            std::cout << "is literal" << std::endl;
            break;
        case CHAR:
            std::cout << "is char" << std::endl;
            break;
        case DOUBLE:
            std::cout << "is double" << std::endl;
            break;
        case FLOAT:
            std::cout << "is float" << std::endl;
            break;
        case INT:
            std::cout << "is int" << std::endl;
            break;
        default:
            std::cout << "error" << std::endl;
    }
}

