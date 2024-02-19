#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template < typename T, class Container = std::deque< T > > 
class MutantStack : public std::stack< T, Container >
{

public:
    typedef typename Container::iterator    iterator;

    MutantStack(void);
    ~MutantStack(void);
    MutantStack(const MutantStack& rhs);
    MutantStack& operator=(const MutantStack& rhs);

    iterator     begin(void);
    iterator     end(void);
};

#include <MutantStack.tpp>

#endif