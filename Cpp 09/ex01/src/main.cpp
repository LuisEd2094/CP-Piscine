#include <RPN.hpp>

void exitError(std::string error)
{
    std::cerr <<"Error: " << error << std::endl;
    std::exit(EXIT_FAILURE);
}


int main (int argc, char *argv[])
{
    std::string input;
    RPN rpn;
    
    if (argc != 2)
        exitError("Incorrect usage, please provide me with a valid Polish mathematical expression");
    input = static_cast<std::string>(argv[1]);
    try
    {
        rpn.solveRPN(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
