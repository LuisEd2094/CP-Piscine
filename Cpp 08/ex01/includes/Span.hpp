/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:39:28 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/02 09:39:31 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <set>
# include <exception>
# include <algorithm>
# include <limits>


class Span
{
    private:
        Span();

    public:
        unsigned int    _n;
        std::multiset<int> _multiset;
        Span(unsigned int n);
        ~Span();
        Span(const Span & other);
        Span& operator=(const Span& rhs);

        void addNumber(int number);
        template <typename T>
        void addNumber(T begin, T end)
        {
            for (T it = begin; it != end; ++it)
                Span::addNumber(*it);
            std::cout << _multiset.size() << _n << std::endl;
        }
        unsigned int shortestSpan();
        unsigned int longestSpan() const;
};

#endif
