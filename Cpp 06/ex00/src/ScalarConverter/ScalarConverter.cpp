#include "ScalarConverter.hpp" 

std::size_t ScalarConverter::m_dot_pos = 0;
std::string ScalarConverter::m_sub_str_int = "";
std::string ScalarConverter::m_str = "";
bool ScalarConverter::m_has_f = false;
bool ScalarConverter::m_has_sign = false;
int ScalarConverter::m_int = 0;
unsigned char ScalarConverter::m_char = 0;
float ScalarConverter::m_float = 0.0f;
double ScalarConverter::m_double = 0.0;
e_type ScalarConverter::m_type = NONE;

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
    std::string str_copy = m_sub_str_int;
    long int strtol_value = 0;
    char *p_end;

    if (m_dot_pos)
        m_sub_str_int = m_sub_str_int.substr(0, m_sub_str_int.find('.'));
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
    if (m_str.length() > 1)
        return (false);
    std::cout << std::isprint(static_cast<unsigned char>(m_str[0])) <<  std::endl;
    return (std::isprint(static_cast<unsigned char>(m_str[0])));
}

bool ScalarConverter::is_double()
{
    return (m_dot_pos && !(m_has_f));
}

bool ScalarConverter::is_float()
{
    return(m_has_f && m_dot_pos);
}

bool ScalarConverter::is_valid_number()
{
    std::string str_copy = m_str;
    std::ptrdiff_t dot_pos;

    for (std::string::iterator it = str_copy.begin(); it < str_copy.end(); it++)
    {
        if (it == str_copy.begin() && (*it == '+' || *it == '-'))
            m_has_sign = 1;
        else if (*it == '.')
        {
            if (it == str_copy.end() - 1)
                return (false);
            else if (!m_dot_pos)
            {
                dot_pos = std::distance(str_copy.begin(), it);
                if (m_has_sign && dot_pos <= 1)
                    return (false);
                else if (dot_pos < 1)
                    return (false);
                else
                    m_dot_pos = dot_pos;
            }
            else
                return (false);
        }
        else if (it == str_copy.end() - 1 && *it == 'f')
        {
            if (*it == 'f' && m_dot_pos && *(it - 1) != '.')
            {
                m_has_f = 1;
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
        if (m_str == literals[i])
            return true;
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

void ScalarConverter::print_char()
{
    std::cout << "print char" << std::endl;
}


void ScalarConverter::print_int()
{
        std::cout << "print int" << std::endl;

}
void ScalarConverter::print_float()
{
        std::cout << "print float" << std::endl;

}
void ScalarConverter::print_double()
{    std::cout << "print double" << std::endl;
}

void ScalarConverter::literal_case()
{
    void (*functions[])()= {
        &ScalarConverter::print_char,
        &ScalarConverter::print_int,
        &ScalarConverter::print_float,
        &ScalarConverter::print_double
    };

    for (size_t i = 0; i < sizeof(functions) / sizeof(functions[0]); ++i){
        functions[i]();
    }


}

void ScalarConverter::convert(char *input)
{
    m_str = static_cast<std::string>(input);
    m_sub_str_int = m_str;

    if (m_str.empty())
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

