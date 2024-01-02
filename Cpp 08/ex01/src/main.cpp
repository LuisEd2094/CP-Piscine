/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:39:48 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/02 09:39:54 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <numeric>
#include <set>
#include <list>

int main( void )
{
    Span span( 10000 );

    try {
        std::list<int>    l( 10000 );
        std::srand( time ( NULL ) );
        std::generate( l.begin(), l.end(), std::rand );


        span.addNumber( l.begin(), l.end() );

        std::cout << "Longest span: " << span.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        
    } catch ( std::exception& e ) {
        std::cout << e.what() << std::endl;
        std::cout <<  span._multiset.size() << std::endl;
    }
    Span span2(10);
    span2.addNumber(5);
    span2.addNumber(2);
    span2.addNumber(8);
    span2.addNumber(1);
    span2.addNumber(5);
    span2.addNumber(5);

    std::cout << "Longest span: " << span2.longestSpan() << std::endl;
    std::cout << "Shortest span: " << span2.shortestSpan() << std::endl;

    // Elements are automatically sorted


    return 0;
}
