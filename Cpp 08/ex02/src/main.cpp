#include <iostream>
#include <list>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <MutantStack.hpp>

int main ()
{
    std::stack<char > stack;


    stack.push(41);
    stack.push(42);


    std::cout << stack.top() << std::endl;
    MutantStack<int> *mutant = new MutantStack<int>();


    mutant->push(1);
    mutant->push(2);
    mutant->push(3);
    mutant->push(4);
    mutant->push(5);
    mutant->push(6);
    mutant->push(7);
    mutant->push(8);
    
    MutantStack<int > mutan;

    mutan = *mutant;

    MutantStack<int>::iterator it = mutant->begin();
    MutantStack<int>::iterator itend = mutant->end();
    

    for (; it != itend ; ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << mutant->top() << std::endl;


    delete mutant;

    std::cout << "About to print from = operator " << std::endl;
    it = mutan.begin();
    itend = mutan.end();
    

    for (; it != itend ; ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << mutan.top() << std::endl;
}
