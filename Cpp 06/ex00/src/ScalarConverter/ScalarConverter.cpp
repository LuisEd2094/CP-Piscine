#include "ScalarConverter.hpp" 

ScalarConverter::ScalarConverter(void) : 
    m_dot_pos(0),
    m_sub_str_int(""),
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
        this->m_has_sign = rhs.m_has_sign;
        this->m_int = rhs.m_int;
        this->m_char = rhs.m_char;
        this->m_float = rhs.m_float;
        this->m_double = rhs.m_double;
    };
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::is_int(const std::string& str)
{
    std::string str_copy = str;
    long int strtol_value = 0;
    char *p_end;

    if (check_if_only_zeros(str_copy))
        return (true);
    strtol_value = strtol(str_copy.c_str(), &p_end, 10);
    if (strtol_value > std::numeric_limits<int>::max())
        return (false);
    else if (strtol_value < std::numeric_limits<int>::min())
        return (false);
    return (strtol_value);
}

bool ScalarConverter::is_char(const std::string& str)
{
    if (str.length() > 1)
        return (false);
    return (std::isprint(static_cast<unsigned char>(str[0])));
}

bool ScalarConverter::is_double()
{

}

bool ScalarConverter::is_float()
{
    if(!this->m_has_f)
        return (false);
}

bool ScalarConverter::is_valid_number(const std::string& str)
{
    std::string str_copy = str;
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


void ScalarConverter::convert(char *input)
{
    std::string str = static_cast<std::string>(input);
    this->m_sub_str_int = str;

    if (str.empty())
        return ;
    //std::cout << this->is_valid_number(str) << std::endl;
    if (!this->is_valid_number(str))
        return;
    if (this->m_dot_pos)
        this->m_sub_str_int = str.substr(0, str.find('.'));
    //std::cout << "dot pos" << this->m_dot_pos << std::endl;
    std::cout << this->m_sub_str_int << std::endl;
    std::cout << this->is_int(this->m_sub_str_int) << std::endl;
    std::cout << this->m_int << std::endl;
    std::cout << this->is_char(str) << std::endl;
    std::cout << this->m_char << std::endl;
   // std::cout << this->is_float(str) << std::endl;

}
