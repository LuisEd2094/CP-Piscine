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

Span::Span(unsigned int n) : _n(n){}
Span::Span(const Span& src) : _n(src._n), _multiset(src._multiset) {}
Span& Span::operator=(const Span& rhs) {
    if (this != &rhs)
    {
        _multiset = rhs._multiset;
        _n = rhs._n;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber (int n)
{
    if (_multiset.size() >= _n)
        throw std::out_of_range("multiset is full");
    _multiset.insert(n);
}


unsigned int Span::longestSpan() const
{
    if (_multiset.size() < 2)
        throw std::out_of_range("multiset too short, no span to be found");
    return (*std::max_element(_multiset.begin(), _multiset.end()) - *std::min_element(_multiset.begin(), _multiset.end()));   
}
unsigned int Span::shortestSpan()
{
    if (_multiset.size() < 2)
        throw std::out_of_range("multiset too short, no span to be found");
    
    unsigned int min_val = std::numeric_limits<int>::max();
    unsigned int difference;
    std::multiset<int>::iterator it = _multiset.begin();
    std::multiset<int>::iterator prevIt = it++;

    for (; it != _multiset.end()--; ++it, ++prevIt)
    {
        difference = *it - *prevIt;
        min_val = std::min(min_val, difference);
    }

    return difference;
}
