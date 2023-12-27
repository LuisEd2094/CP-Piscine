#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    ScalarConverter converter;

    if (argc == 1)
        std::cout << "Give me something to convert!" << std::endl;
    else if (argc > 2)
        std::cout << "Give just ONE thing to convert" << std::endl;
    else
        converter.convert(argv[1]);
    std::exit(EXIT_SUCCESS);
}