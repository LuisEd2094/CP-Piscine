#include "easyfind.hpp"
#include <algorithm>

int main( int ac, char ** av )
{
    if ( ac != 2 )
        return EXIT_FAILURE;

    int                 arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector< int >      vect( arr, arr + sizeof( arr ) / sizeof( int ) );
    std::list< int >        list( arr, arr + sizeof( arr ) / sizeof( int ) );

    try
    {
    easyfind( vect, std::atoi( av[1] ));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        easyfind( list, std::atoi( av[1] ));

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    return EXIT_SUCCESS;
}
