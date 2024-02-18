/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:39:38 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/02 09:39:41 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp" 

Span::Span(unsigned int n) : _n(n),  _shortestSpan(std::numeric_limits<int>::max()) {}

Span::Span(const Span& src) : _n(src._n), _shortestSpan(std::numeric_limits<int>::max()) , _multiset(src._multiset) {}

Span& Span::operator=(const Span& rhs) {
    if (this != &rhs)
    {
        _multiset = rhs._multiset;
        _n = rhs._n;
        _shortestSpan = rhs._shortestSpan;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber (int n)
{
    if (_multiset.size() >= _n)
        throw std::out_of_range("multiset is full");
    _multiset.insert(n);
    if (_multiset.size() >= 2)
    {
        std::multiset<int>::iterator num = _multiset.find(n);
         if (num != _multiset.begin())
        {
            std::multiset<int>::iterator prev = num;

            _shortestSpan = std::min(_shortestSpan, static_cast<unsigned int>(*num - (*--prev))); 
        }
        if (num != --_multiset.end())
        {
            std::multiset<int>::iterator next = num;
            _shortestSpan = std::min(_shortestSpan,  static_cast<unsigned int>(*(++next) - *num));
        }
    }
}


unsigned int Span::longestSpan() const
{
    if (_multiset.size() < 2)
        throw std::out_of_range("multiset too short, no span to be found");
    return (*(--_multiset.end()) - *_multiset.begin());
}
unsigned int Span::shortestSpan() const
{
    if (_multiset.size() < 2)
        throw std::out_of_range("multiset too short, no span to be found");

    return (_shortestSpan);
    unsigned int min_val = std::numeric_limits<int>::max();
    unsigned int difference;

    std::multiset<int>::iterator it = _multiset.begin();
    std::multiset<int>::iterator prev_it = it++;

    for (; it != --_multiset.end(); ++it, ++prev_it)
    {
        difference = *it - *prev_it;
        min_val = std::min(min_val, difference);
    }

    return (min_val);
}
