#include <RPN.hpp> 

RPN::RPN(void) {}
RPN::RPN(const RPN& src) {*this = src;}
RPN& RPN::operator=(const RPN& rhs) 
{
    if (this != &rhs)
    {
        _stack = rhs._stack;
    }    
    return (*this);
}
RPN::~RPN() {}


bool    RPN::checkValidNumber(std::string &number)
{
    std::size_t len = number.length();
    if (len == 1)
        return  (true);
    else if (len == 2 && (isdigit(number[0]) || number[0] == '-' || number[0] == '+'))
        return (true);
    else
        return (false);

}

int RPN::sum(int first, int second)
{
    return (first + second);
}

int RPN::sub(int first, int second)
{
    return (first - second);
}
int RPN::multi(int first, int second)
{
    return (first * second);
}
int RPN::div(int first, int second)
{
    return (first / second);
}


int RPN::getValFromStack(std::string &symbol)
{
    int value; 
    if (_stack.empty())
        throw RPN::parseException("Unexpected token: " + symbol); 
    value = _stack.top();
    _stack.pop();
    return (value);
}

void RPN::solveOperation(std::string &symbol)
{
    int firstVal, secondVal;
    symbol_info info [] =  {
        {"+", &RPN::sum},
        {"-", &RPN::sub},
        {"*", &RPN::multi},
        {"/", &RPN::div}, 
    };

    secondVal = getValFromStack(symbol);
    firstVal = getValFromStack(symbol);
    for (int i = 0; i < 4; ++i)
    {
        if (info[i].symbol == symbol)
            _stack.push((info[i].f)(firstVal, secondVal));
    }

    //std::cout << firstVal << " " + symbol + " " << secondVal << std::endl; 

}

void RPN::solveRPN(std::string str)
{
    std::stringstream       iss(str);
    std::string             parse;

    while (getline(iss, parse, ' '))
    {
        if (isdigit(*(--parse.end())))
        {
            if (!checkValidNumber(parse))
                throw RPN::parseException("Valid numbers should be less than 10 not :" + parse);
            _stack.push(std::atoi(parse.c_str()));
        }
        else if (parse.length() != 1 || parse.find_first_of("+-/*")  == std::string::npos )
            throw RPN::parseException("Invalid input: " + parse);
        else
            solveOperation(parse);
    }
    if (_stack.size() != 1)
        throw RPN::parseException("Calculation expression incomplete, we are missing symbols!");
    std::cout << _stack.top() << std::endl;

}
