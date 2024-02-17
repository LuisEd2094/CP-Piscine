/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:55:09 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:55:10 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    std::srand(static_cast<unsigned int>(std::clock()));

    int random1 = std::rand();

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
