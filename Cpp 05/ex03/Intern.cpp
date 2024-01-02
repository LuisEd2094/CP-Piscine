/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:50:29 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:51:25 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp" 

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern & other) {
    *this = other; 

}

Intern& Intern::operator=(const Intern & rhs) {
    (void)rhs;
    return (*this);
}

std::string Intern::tolower(std::string& str)
{

	std::string::iterator it;
	
	for (it = str.begin(); it < str.end(); it++) 
    	*it = std::tolower(*it);
	return (str);
}

static AForm *newShrubbery(const std::string target) {
	return new ShrubberyCreationForm(target);
}

static AForm *newRobotomy(const std::string target) {
	return new RobotomyRequestForm(target);
}

static AForm *newPresidential(const std::string target) {
	return new PresidentialPardonForm(target);
}

typedef AForm *(*FormConstructorPtr)(const std::string);


AForm* Intern::makeForm(const std::string& form, const std::string target)
{
    std::string copy = form;
    std::string valid_forms[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    FormConstructorPtr forms[]= {
        &newShrubbery,
        &newRobotomy,
        &newPresidential
    };

    tolower(copy);
    for (int i = 0; i < 3; i++)
    {
        if (copy == valid_forms[i])
        {
            return (forms[i](target));
        }
    }
    return (NULL);
}
