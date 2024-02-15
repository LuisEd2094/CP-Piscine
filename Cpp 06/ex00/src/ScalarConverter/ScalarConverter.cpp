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
    _char = _str[0];
    return (std::isprint((_char)));
}

bool ScalarConverter::is_double()
{

    // need to check valid double max and min
    if (_dot_pos && !(_has_f))
    {
        _double = std::stof(_str);
    }
    return (_dot_pos && !(_has_f));
}

unsigned int ScalarConverter::get_presicion()
{
    if (_has_f)
        return (_str.length() - _dot_pos - 2);
    else if (!_dot_pos)
        return (1);
    else
        return (_str.length() - _dot_pos - 1);
}


bool ScalarConverter::is_float()
{
    // need to check valid float max and min

    if (_has_f && _dot_pos)
        _float = std::stof(_str);
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
        {DOUBLE, &ScalarConverter::is_double},
        {FLOAT, &ScalarConverter::is_float},
        {INT, &ScalarConverter::is_int},
        {CHAR, &ScalarConverter::is_char},

    };
    if (is_literal())
        return (LITERALS);
    if (!is_valid_number())
        return (NONE);
    for (size_t i = 0; i < sizeof(valid_types) / sizeof(valid_types[0]); ++i) {
        if ((valid_types[i].f)()) {
           std::cout << std::fixed << std::setprecision(get_presicion()); 
           return (valid_types[i].type);
        }
    }
    return (NONE);
}

void ScalarConverter::print_char(std::string str)
{
    std::cout << "char: ";
    if (!str.empty())
        std::cout << str << std::endl;
    else
        std::cout << _char << std::endl;
}


void ScalarConverter::print_int(std::string str)
{
    std::cout << "int: ";
    if (!str.empty())
        std::cout << str << std::endl;
    else
        std::cout << _int << std::endl;
}
void ScalarConverter::print_float(std::string str)
{
    std::cout << "float: ";
    if (!str.empty())
        std::cout << str << std::endl;
    else{
        std::cout << _float << "f" << std::endl;

    }

}
void ScalarConverter::print_double(std::string str)
{    
    std::cout << "double: ";
    if (!str.empty())
        std::cout << str << std::endl;
    else
        std::cout << _double << std::endl;
}

void ScalarConverter::literal_case()
{
    print_char("imposible");
    print_int("imposible");
    print_float((_str.back() == 'f' && _str.back() - 1 == 'f') ? \
                _str : _str + "f");

    print_double((_str.back() == 'f' && _str.back() - 1 == 'f') ? \
                _str.substr(0, _str.size() - 1) : _str);
}


void ScalarConverter::float_case()
{
    _char = static_cast<char>(_float);
    _int = static_cast<int>(_float);
    _double = static_cast<double>(_float);
    
    print_char("");
    print_int("");
    print_float("");
    print_double("");
}


void ScalarConverter::char_case()
{
    _int = static_cast<int>(_char);
    _float = static_cast<float>(_char);
    _double = static_cast<double>(_char);
    print_char("");
    print_int("");
    print_float("");
    print_double("");
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
            break;
        case CHAR:
            char_case();
            std::cout << "is char" << std::endl;
            break;
        case DOUBLE:
            double_case();
            std::cout << "is double" << std::endl;
            break;
        case FLOAT:
            float_case();
            std::cout << "is float" << std::endl;
            break;
        case INT:
            std::cout << "is int" << std::endl;
            break;
        default:
            std::cout << "error" << std::endl;
    }
}

