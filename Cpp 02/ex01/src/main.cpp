/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:22:11 by lsoto-do          #+#    #+#             */
/*   Updated: 2023/12/26 13:22:12 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <typeinfo>

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as " << typeid(a.toInt()).name() << std::endl;
	std::cout << "b is " << b.toInt() << " as " << typeid(a.toInt()).name() << std::endl;
	std::cout << "c is " << c.toInt() << " as " << typeid(a.toInt()).name() << std::endl;
	std::cout << "d is " << d.toInt() << " as " << typeid(a.toInt()).name() << std::endl;

	std::cout << std::endl;

	std::cout << "a is " << a.toFloat() << " as " << typeid(a.toFloat()).name() << std::endl;
	std::cout << "b is " << b.toFloat() << " as " << typeid(a.toFloat()).name() << std::endl;
	std::cout << "c is " << c.toFloat() << " as " << typeid(a.toFloat()).name() << std::endl;
	std::cout << "d is " << d.toFloat() << " as " << typeid(a.toFloat()).name() << std::endl;

	return 0;
}
