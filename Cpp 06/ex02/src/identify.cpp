#include "identify.hpp"


Base* createA() {
    return new A;
}

Base* createB() {
    return new B;
}

Base* createC() {
    return new C;
}

Base* generate(void)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::random_device rd;
    std::default_random_engine generator(rd());

    // Generate two random integers
    std::uniform_int_distribution<int> distribution(0, std::numeric_limits<int>::max());
    int random1 = distribution(generator);

    int index = random1 % 3;

    Base* (*constructors[])() = {
        createA,
        createB,
        createC
    };

    return (constructors[index]());
}


void identify(Base* p)
{
    if (dynamic_cast <A*>(p))
        std::cout << "Is a pointer to Base A" << std::endl;
    else if (dynamic_cast <B*>(p))
        std::cout << "Is a pointer to Base B" << std::endl;
    else if (dynamic_cast <C*>(p))
        std::cout << "Is a pointer to  Base C" << std::endl;
    else
        std::cout << "This is not any of the child classes" << std::endl;
}

void identify(Base& p)
{
    try 
    {
        A& refA = dynamic_cast<A&>(p);
        std::cout << "Is reference Base A" << std::endl;
        std::cout << &refA << std::endl;
        return ;
    } 
    catch (std::bad_cast& e) 
    {
    }

    try 
    {
        B& refB = dynamic_cast<B&>(p);
        std::cout << "Is reference Base B" << std::endl;
        std::cout << &refB << std::endl;
        return ;
    } 
    catch (std::bad_cast& e) 
    {
    }
    try 
    {
        C& refC = dynamic_cast<C&>(p);
        std::cout << "Is reference Base C" << std::endl;
        std::cout << &refC << std::endl;

    }
    catch (std::bad_cast& e) 
    {
        std::cout << "The object reference is not a child" << std::endl;
        return;
    }
}
