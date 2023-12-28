#include "ScalarConverter.hpp" 

ScalarConverter::ScalarConverter(void) : 
    m_dot_pos(0),
    m_sub_str_int(""),
    m_str(""),
    m_has_f(0),
    m_has_sign(0),
    m_int(0),
    m_char(0),
    m_float(0),
    m_double(0),
    m_type(NONE)

    {}
ScalarConverter::ScalarConverter(const ScalarConverter& src): 
    m_dot_pos(src.m_dot_pos),
    m_sub_str_int(src.m_sub_str_int),
    m_str(src.m_str),
    m_has_f(src.m_has_f),
    m_has_sign(src.m_has_sign),
    m_int(src.m_int),
    m_char(src.m_char),
    m_float(src.m_float),
    m_double(src.m_double), 
    m_type(src.m_type)
    {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
    if (this != &rhs)
    {
        this->m_dot_pos = rhs.m_dot_pos;
        this->m_has_f = rhs.m_has_f;
        this->m_sub_str_int = rhs.m_sub_str_int;
        this->m_str = rhs.m_str;
        this->m_has_sign = rhs.m_has_sign;
        this->m_int = rhs.m_int;
        this->m_char = rhs.m_char;
        this->m_float = rhs.m_float;
        this->m_double = rhs.m_double;
    };
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::is_int()
{
    std::string str_copy = this->m_sub_str_int;
    long int strtol_value = 0;
    char *p_end;

    if (this->m_dot_pos)
        this->m_sub_str_int = this->m_sub_str_int.substr(0, this->m_sub_str_int.find('.'));
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
    if (this->m_str.length() > 1)
        return (false);
    return (std::isprint(static_cast<unsigned char>(this->m_str[0])));
}

bool ScalarConverter::is_double()
{
    return (this->m_dot_pos && !(this->m_has_f));
}

bool ScalarConverter::is_float()
{
    return(this->m_has_f && this->m_dot_pos);
}

bool ScalarConverter::is_valid_number()
{
    std::string str_copy = this->m_str;
    std::ptrdiff_t dot_pos;

    for (std::string::iterator it = str_copy.begin(); it < str_copy.end(); it++)
    {
        if (it == str_copy.begin() && (*it == '+' || *it == '-'))
            this->m_has_sign = 1;
        else if (*it == '.')
        {
            if (it == str_copy.end() - 1)
                return (false);
            else if (!this->m_dot_pos)
            {
                dot_pos = std::distance(str_copy.begin(), it);
                if (this->m_has_sign && dot_pos <= 1)
                    return (false);
                else if (dot_pos < 1)
                    return (false);
                else
                    this->m_dot_pos = dot_pos;
            }
            else
                return (false);
        }
        else if (it == str_copy.end() - 1 && *it == 'f')
        {
            if (*it == 'f' && this->m_dot_pos && *(it - 1) != '.')
            {
                this->m_has_f = 1;
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




e_type ScalarConverter::check_type()
{
    type_info valid_types [] = {
        {CHAR, &ScalarConverter::is_char},
        {DOUBLE, &ScalarConverter::is_double},
        {FLOAT, &ScalarConverter::is_float},
        {INT, &ScalarConverter::is_int}
    };

    for (size_t i = 0; i < sizeof(valid_types) / sizeof(valid_types[0]); ++i) {
        if ((this->*valid_types[i].f)()) {
            return valid_types[i].type;
        }
    }
    return (NONE);
}

void ScalarConverter::convert(char *input)
{
    this->m_str = static_cast<std::string>(input);
    this->m_sub_str_int = this->m_str;

    if (this->m_str.empty())
        return ;
    //std::cout << this->is_valid_number(str) << std::endl;
    if (!this->is_valid_number())
        return ;
    switch (this->check_type())
    {
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
    
    if (this->m_dot_pos)
        this->m_sub_str_int = this->m_sub_str_int.substr(0, this->m_sub_str_int.find('.'));
    //std::cout << "dot pos" << this->m_dot_pos << std::endl;
    /*std::cout << this->m_sub_str_int << std::endl;
    std::cout << this->is_int() << std::endl;
    std::cout << this->m_int << std::endl;
    std::cout << this->is_char() << std::endl;
    std::cout << this->m_char << std::endl;*/
   // std::cout << this->is_float(str) << std::endl;

}

