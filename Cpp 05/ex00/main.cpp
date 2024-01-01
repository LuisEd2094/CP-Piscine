/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:45:31 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:45:32 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void upAndDownTest()
{
    Bureaucrat john("John", 2);
	Bureaucrat jim("Jim", 149);

	try
	{
		std::cout << john << std::endl;
		std::cout << jim << std::endl;
		john.incrementGrade();
		jim.decrementGrade();
		std::cout << john << std::endl;
		std::cout << jim << std::endl;
		john.incrementGrade();
		jim.decrementGrade();
		std::cout << john << std::endl;
		std::cout << jim << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void creationTest()
{
    try
    {
        Bureaucrat john("John", 999999999);
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat john("John", -999999999);
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    Bureaucrat john;

    std::cout << john;
}

int main()
{
    //upAndDownTest();
    //creationTest();
    Bureaucrat John("John", 100);
    Bureaucrat Alice;

    Alice = John;

    std::cout << Alice;
    std::cout << John;
}
