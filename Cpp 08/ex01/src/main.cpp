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

    // generate a list of numbers and then add them to the span object
    try {
        std::list<int>    l( 10000 );
        std::srand( time ( NULL ) );
        std::generate( l.begin(), l.end(), std::rand );


        span.addNumber( l.begin(), l.end() );

        std::cout << "Longest span: " << span.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        
    } catch ( std::exception& e ) {
        std::cout << e.what() << std::endl;
    }
    // Test to see what happens if you add once its full
    try {
        std::list<int>    l( 10000 );
        std::srand( time ( NULL ) );
        std::generate( l.begin(), l.end(), std::rand );


        span.addNumber( l.begin(), l.end() );

        std::cout << "Longest span: " << span.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        
    } catch ( std::exception& e ) {
        std::cout << e.what() << std::endl;
    }
    Span span2(10);
    span2.addNumber(5);
    span2.addNumber(3);
    span2.addNumber(9);
    span2.addNumber(-9);
    span2.addNumber(-11);
    span2.addNumber(11);

    try
    {

        std::cout << "Longest span: " << span2.longestSpan() << std::endl;
        std::cout << "Shortest span: " << span2.shortestSpan() << std::endl;    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    


    // Elements are automatically sorted


    return 0;
}
