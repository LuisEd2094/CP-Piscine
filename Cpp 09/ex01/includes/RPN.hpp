#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstdlib>
# include <stack>
# include <sstream>
# include <string>
# include <limits>
# include <numeric>

class RPN
{
    private:
        std::stack<int> _stack;

        bool    checkValidNumber(std::string &number);
        void    solveOperation(std::string &symbol);
        int     getValFromStack(std::string &symbol);

        static void     checkIntOverflow(long &protection);
        static int     sum(int first, int second);
        static int     sub(int first, int second);
        static int     div(int first, int second);
        static int     multi(int first, int second);
    public:
        RPN();
        ~RPN();
        RPN(const RPN & other);
        RPN& operator=(const RPN& rhs);
        void solveRPN(std::string str);
        class RPNException : public std::exception
        {
            private:
                std::string _message;
            public:
                RPNException(std::string message): _message(message) {}
                ~RPNException() throw() {}
                const char * what() const throw()
                {
                    return (_message.c_str());
                }
        };

};

typedef int (*symbol_function)(int, int);

struct symbol_info {
    std::string symbol;
    symbol_function f;
};
#endif