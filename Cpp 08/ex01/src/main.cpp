#include "Span.hpp"
#include <vector>
#include <numeric>
#include <set>
int main( void )
{
    std::cout << "---- TEST #1 -----" << std::endl;

    Span sp = Span( 5 );

    sp.addNumber( 6 );
    sp.addNumber( 3 );
    sp.addNumber( 9 );
    sp.addNumber( 17 );
    sp.addNumber( 11 );


    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;

    std::cout << "\n---- TEST #1 -----" << std::endl;

    try {
        std::list<int>    l( 10000 );
        std::srand( time ( NULL ) );
        std::generate( l.begin(), l.end(), std::rand );

        Span span( l.size() );

        span.addNumber( l.begin(), l.end() );

        std::cout << "Longest span: " << span.longestSpan() << std::endl;
        // std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        
    } catch ( std::exception& e ) {
        std::cout << e.what() << std::endl; 
    }
    std::set<int> mySet;

    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);
    mySet.insert(1);

    // Elements are automatically sorted
    for (std::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}