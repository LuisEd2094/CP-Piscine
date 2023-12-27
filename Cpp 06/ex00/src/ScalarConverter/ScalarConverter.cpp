#include "ScalarConverter.hpp" 

ScalarConverter::ScalarConverter(void) : m_dot_pos(0),  m_sub_str_int(""), m_has_f(0), m_has_sign(0) {}
ScalarConverter::ScalarConverter(const ScalarConverter& src): m_dot_pos(src.m_dot_pos), m_sub_str_int(src.m_sub_str_int), m_has_f(src.m_has_f), m_has_sign(src.m_has_sign) { 
    }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
    if (this != &rhs)
    {
        this->m_dot_pos = rhs.m_dot_pos;
        this->m_has_f = rhs.m_has_f;
        this->m_sub_str_int = rhs.m_sub_str_int;
        this->m_has_sign = rhs.m_has_sign;
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
    if (!is_only_numbers(str_copy))
        return (false);
    if (str_copy.empty())
        return (false);
    strtol_value = strtol(str_copy.c_str(), &p_end, 10);
    if (strtol_value > std::numeric_limits<int>::max())
        return (false);
    else if (strtol_value < std::numeric_limits<int>::min())
        return (false);
    return (strtol_value);
}

bool ScalarConverter::is_char(const std::string str)
{
    if (str.length() > 1)
        return (false);
    return (std::isprint(static_cast<unsigned char>(str[0])));

}

bool ScalarConverter::isFloat(const std::string str)
{
    std::istringstream iss(str);
    float f;
    iss >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail(); 
}

bool ScalarConverter::is_valid_number(const std::string& str)
{
    std::string str_copy = str;

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
                if (this->m_has_sign && std::distance(str_copy.begin(), it) <= 1)
                    return (false);
                else if (std::distance(str_copy.begin(), it) < 1)
                    return (false);
                else
                    this->m_dot_pos = 1;
            }
            else
                return (false);
        }
        else if (it == str_copy.end() - 1 && *it == 'f')
        {
            if (*it == 'f' && this->m_dot_pos && *(it - 1) != '.')
                return (true);
            else
                return (false);
        }
        else if (!isdigit(*it))
            return (false);
    }
    return (true);
}


void ScalarConverter::convert(char *input)
{
    std::string str = static_cast<std::string>(input);
    this->m_sub_str_int = str;
    if (str.empty())
    {
        std::cout << "Is empty" << std::endl;
        return ;
    }
    //std::cout << this->is_valid_number(str) << std::endl;
    if (!this->is_valid_number(str))
        return;
    if (this->m_dot_pos)
        this->m_sub_str_int = str.substr(0, str.find('.'));
    //std::cout << "dot pos" << this->m_dot_pos << std::endl;
    std::cout << this->m_sub_str_int << std::endl;
    std::cout << this->is_int(this->m_sub_str_int) << std::endl;
   // std::cout << this->is_char(str) << std::endl;
   // std::cout << this->isFloat(str) << std::endl;
}

