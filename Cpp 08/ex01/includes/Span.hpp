#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include <exception>
# include <algorithm>
# include <limits>
class Span
{
    private:
        Span();
        unsigned int    m_n;
        std::list<int>  m_list;
    public:
        Span(unsigned int n);
        ~Span();
        Span(const Span & other);
        Span& operator=(const Span& rhs);

        void addNumber(int number);
        void addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end);
        unsigned int shortestSpan();
        unsigned int longestSpan() const;
};

#endif