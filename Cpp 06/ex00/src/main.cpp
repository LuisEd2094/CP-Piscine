#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cerr << "Give me something to convert!" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    else if (argc > 2)
    {
        std::cerr << "Give just ONE thing to convert" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    else
        ScalarConverter::convert(argv[1]);
    std::exit(EXIT_SUCCESS);
}
