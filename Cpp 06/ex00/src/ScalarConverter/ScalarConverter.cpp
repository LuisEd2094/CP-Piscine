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

std::size_t     ScalarConverter::_dot_pos = 0;
std::string     ScalarConverter::_str = "";
std::string     ScalarConverter::_literal = "";
bool            ScalarConverter::_has_f = false;
bool            ScalarConverter::_has_sign = false;
int             ScalarConverter::_int = 0;
unsigned char   ScalarConverter::_char = 0;
float           ScalarConverter::_float = 0.0f;
double          ScalarConverter::_double = 0.0;
long int        ScalarConverter::_strtol_value = 0;
e_type          ScalarConverter::_type = NONE;
char*           ScalarConverter::_p_end = NULL;

std::streamsize ScalarConverter::_og_precision = std::cout.precision();


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

/*strtod sets errno to ERANGE if it goes beyond the limit. there are issues with the precision of the conversion
so large numbers are rounded to the nearest double*/

bool ScalarConverter::is_double()
{
    if (_dot_pos && !(_has_f))
    {
        _double = std::strtod(_str.c_str(), &_p_end);
        return (errno != ERANGE);
    }
    return (false);
}

bool ScalarConverter::is_float()
{
    if (_has_f && _dot_pos)
    {
        _double = std::strtof(_str.c_str(), &_p_end);
        if (errno == ERANGE)
            return (false);
        if (_double > std::numeric_limits<float>::max() || _double < std::numeric_limits<float>::max() * -1)
            return (false);
        _float = std::atof(_str.c_str());
        return (true);
    }
    return (false);
}

bool ScalarConverter::is_int()
{
    if (check_if_only_zeros(_str))
        return (true);
    _strtol_value = strtol(_str.c_str(), &_p_end, 10);
    if (_strtol_value > std::numeric_limits<int>::max() || _strtol_value < std::numeric_limits<int>::min())
        return (false);
    _int = std::atoi(_str.c_str());
    return (true);
}

bool ScalarConverter::is_char()
{
    if (_str.length() > 1)
        return (false);
    _char = _str[0];
    return (std::isprint((_char)));
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

unsigned int ScalarConverter::get_presicion()
{
    if (_has_f)
        return (_str.length() - _dot_pos - 2);
    else if (!_dot_pos)
        return (1);
    else
        return (_str.length() - _dot_pos - 1);
}

e_type ScalarConverter::check_type()
{
    type_info valid_types [] = {
        {DOUBLE, &ScalarConverter::is_double},
        {FLOAT, &ScalarConverter::is_float},
        {CHAR, &ScalarConverter::is_char},
        {INT, &ScalarConverter::is_int}

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


void ScalarConverter::print_double(std::string str)
{    
    std::cout << "double: ";
    if (!str.empty())
        std::cout << str << std::endl;
    else
        std::cout << _double << std::endl;
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

void ScalarConverter::print_int(std::string str)
{
    std::cout << "int: ";
    if (!str.empty())
        std::cout << str << std::endl;
    else
        std::cout << _int << std::endl;
}

void ScalarConverter::print_char(std::string str)
{
    std::cout << "char: ";
    if (!str.empty())
        std::cout << str << std::endl;
    else
        std::cout << _char << std::endl;
}

void ScalarConverter::literal_case()
{
    print_char("imposible");
    print_int("imposible");
    print_float(((*(_str.rbegin()) == 'f' && *(_str.rbegin() + 1) == 'f') || _str == "nanf") ? _str : _str + "f");
    print_double(((*(_str.rbegin()) == 'f' && *(_str.rbegin() + 1) == 'f') || _str == "nanf")? (_str.substr(0, _str.size() - 1)) : _str);
}

std::string ScalarConverter::get_float_val()
{
    if (_double > std::numeric_limits<float>::max() || _double < std::numeric_limits<float>::max() * -1)
        return ("Value out of bounds");
    else
    {
        _float = static_cast<float>(_double);
        return ("");
    }

}
std::string ScalarConverter::get_int_val()
{
    if (_double > std::numeric_limits<int>::max() || _double < std::numeric_limits<int>::min())
        return ("Value out of bounds");
    else
    {
        _int = static_cast<int>(_double);
        return ("");
    }
}

std::string ScalarConverter::get_char_val()
{
    if (_int < 33 || _int > 126)
        return ("Non displayable");
    else
    {
        _char = static_cast<char>(_int);
        return ("");
    }

}

void ScalarConverter::double_case()
{
    print_double("");
    print_float(get_float_val());
    print_int(get_int_val());
    print_char(get_char_val());
}

void ScalarConverter::float_case()
{
    _double = static_cast<double>(_float);

    print_double("");
    print_float("");
    print_int(get_int_val());
    print_char(get_char_val());
}


void ScalarConverter::int_case()
{
    _double = static_cast<double>(_int);
    _float  = static_cast<float>(_int);

    print_double("");
    print_float("");
    print_int("");
    print_char(get_char_val());
}


void ScalarConverter::char_case()
{
    _double = static_cast<double>(_char);
    _float = static_cast<float>(_char);
    _int = static_cast<int>(_char);

    print_double("");
    print_float("");
    print_int("");
    print_char("");
}







void ScalarConverter::convert(char *input)
{
    _str = static_cast<std::string>(input);

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
        case DOUBLE:
            double_case();
            std::cout << "is double" << std::endl;
            break;
        case FLOAT:
            float_case();
            std::cout << "is float" << std::endl;
            break;
        case INT:
            int_case();
            std::cout << "is int" << std::endl;
            break;
        case CHAR:
            char_case();
            std::cout << "is char" << std::endl;
            break;
        default:
            std::cout << "error" << std::endl;
    }
    std::cout.precision(_og_precision);
}

