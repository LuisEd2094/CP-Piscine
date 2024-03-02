/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:50:50 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:50:59 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


void interTest()
{
    Intern intern;

    try
    {
        AForm *form = intern.makeForm("presidential pardon", "Bender");

        std::cout << *form;

        delete form;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        AForm *form = intern.makeForm("test", "Bender");
        std::cout << *form;

        delete form;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

}

int main()
{
    interTest();
}
