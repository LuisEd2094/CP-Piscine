#include "Span.hpp" 

Span::Span(unsigned int n) : m_n(n){}
Span::Span(const Span& src) : m_n(src.m_n), m_list(src.m_list) {}
Span& Span::operator=(const Span& rhs) {
    if (this != &rhs)
    {
        this->m_list = rhs.m_list;
        this->m_n = rhs.m_n;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber (int n)
{
    if (this->m_list.size() > this->m_n)
        throw std::out_of_range("List is full");
    this->m_list.push_back(n);
}

void Span::addNumber(std::list<int>::const_iterator begin, std::list<int>::const_iterator end)
{
    if (this->m_list.size() > this->m_n)
        throw std::out_of_range("List is full");
    this->m_list.insert(this->m_list.end(), begin, end);
}


unsigned int Span::longestSpan() const
{
    if (this->m_list.size() < 2)
        throw std::out_of_range("List too short, no span to be found");
    return (*std::max_element(this->m_list.begin(), this->m_list.end()) - *std::min_element(this->m_list.begin(), this->m_list.end()));
    
}
unsigned int Span::shortestSpan()
{
    if (this->m_list.size() < 2)
        throw std::out_of_range("List too short, no span to be found");
    
    //int max = std::numeric_limits<int>::max();
    this->m_list.sort();
    //std::list<int> differences(this->m_list.size());
    //std::adjacent_difference(this->m_list.begin(), this->m_list.end(), differences.begin());
    std::cout << "Sorted List: ";
    for (std::list<int>::iterator it = this->m_list.begin(); it != this->m_list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 1;
}
