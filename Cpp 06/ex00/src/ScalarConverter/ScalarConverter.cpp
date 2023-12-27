#include "ScalarConverter.hpp" 

ScalarConverter::ScalarConverter(void) {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { 
    (void)src;
    }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
    (void)rhs;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isInt(const std::string str)
{
    long int strtol_value = 0;
    char *p_end;

    if (check_if_only_zeros(str))
        return (true);
    if (!is_only_numbers(str))
        return (false);
    strtol_value = strtol(str.c_str(), &p_end, 10);
    if (strtol_value > INT_MAX)
        return (false);
    else if (strtol_value < INT_MIN)
        return (false);
    return (true);
}

void ScalarConverter::convert(char *input)
{
    std::string str = static_cast<std::string>(input);
    str = remove_white_space(str);
    if (str.empty())
    {
        std::cout << "Is empty" << std::endl;
        return ;
    }
    std::cout << this->isInt(str) << std::endl;
    //std::cout << this->isChar(str) << std::endl;
}