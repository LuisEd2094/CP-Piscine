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
    else if (len == 2 && ((number[0] == '1' || number[0] == '0') && isdigit(number[1])))
        return (true);
    else
        return (false);

}

/*Static Funtions*/
void RPN::checkIntOverflow(long &protection)
{
    if (protection > std::numeric_limits<int>::max() || protection < std::numeric_limits<int>::min())
        throw RPN::RPNException("Int overflow.");
}

int RPN::sum(int first, int second)
{
    long protection = static_cast<long>(first) + static_cast<long>(second);
    
    checkIntOverflow(protection);
    return (first + second);
}

int RPN::sub(int first, int second)
{
    long protection = static_cast<long>(first) - static_cast<long>(second);
    
    checkIntOverflow(protection);
    return (first - second);
}
int RPN::multi(int first, int second)
{
    long protection = static_cast<long>(first) * static_cast<long>(second);
    
    checkIntOverflow(protection);
    return (first * second);
}
int RPN::div(int first, int second)
{
    if (second == 0)
        throw RPN::RPNException("Can't divide by 0!");
    return (first / second);
}


int RPN::getValFromStack(std::string &symbol)
{
    int value; 
    if (_stack.empty())
        throw RPN::RPNException("Unexpected token: " + symbol); 
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
    std::size_t             len;

    while (getline(iss, parse, ' '))
    {
        len = parse.length();
        if (len > 2)
            throw RPN::RPNException("Invalid input: " + parse);
        else
        {
            if (len == 1 && !isdigit(*parse.begin()))
            {
                if (parse.find_first_of("+-/*")  == std::string::npos )
                        throw RPN::RPNException("Invalid input: " + parse);
                solveOperation(parse);

            }
            else 
            {
                if (!checkValidNumber(parse))
                    throw RPN::RPNException("Valid numbers should be less than 10 not :" + parse);
                _stack.push(std::atoi(parse.c_str()));

            } 

        }
    }
    if (_stack.size() != 1)
        throw RPN::RPNException("Calculation expression incomplete, we are missing symbols!");
    std::cout << _stack.top() << std::endl;

}
