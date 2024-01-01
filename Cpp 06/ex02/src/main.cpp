/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:55:15 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:55:16 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "identify.hpp"
#include <iostream>
#include <typeinfo>



int main()
{
    Base* random_1 = generate(); 
    Base* random_2 = generate();
    Base* random_3 = generate();
    Base* base = new Base;

    identify(random_1);
    identify(random_2);
    identify(random_3);
    identify(base);

    identify(*random_1);
    identify(*random_2);
    identify(*random_3);
    identify(*base);

    delete random_1;
    delete random_2;
    delete random_3;
    delete base;


}
