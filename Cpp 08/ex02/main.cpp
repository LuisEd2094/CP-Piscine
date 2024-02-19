#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <deque>

template< typename T, class Container = std::deque< T > > 
class MutantStack : public std::stack< T, Container >
{

private:

public:

    MutantStack( void ) {};
    ~MutantStack( void ) {};

    MutantStack( const MutantStack& rhs ) { *this = rhs; }
    MutantStack&    operator=( const MutantStack& rhs ) {
        std::stack< T, Container >::operator=( rhs );
        return *this;
    }

    typedef typename Container::iterator    iterator;

    iterator    begin() { return this->c.begin(); }
    iterator    end() { return this->c.end(); }
};

int main ()
{
    std::stack<int> stack;


    stack.push(1);
    stack.push(2);


    MutantStack<int> mutant;

    mutant.push(1);
    stack.push(2);


    MutantStack<int>::iterator it;

    std::cout << mutant.top() << std::endl;

    for (int i = 0; i < 2; ++i)
    {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }
}