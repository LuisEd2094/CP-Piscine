#include <MutantStack.hpp>

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(void){}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack(void){}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& rhs)
{   
    *this = rhs;
}

template <typename T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& rhs) 
{
    std::stack< T, Container >::operator=(rhs);
    std::cout <<  "calling = operator" << std::endl;
    return (*this);
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(void)
{
    return (this->c.begin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(void)
{
    return (this->c.end());
}
