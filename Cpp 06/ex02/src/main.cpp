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
    Base* rando_1 = generate(); 
    Base* rando_2 = generate();
    Base* rando_3 = generate();
    Base* base = new Base;

    identify(rando_1);
    identify(rando_2);
    identify(rando_3);
    identify(base);

    identify(*rando_1);
    identify(*rando_2);
    identify(*rando_3);
    identify(*base);

    delete rando_1;
    delete rando_2;
    delete rando_3;
    delete base;


}
