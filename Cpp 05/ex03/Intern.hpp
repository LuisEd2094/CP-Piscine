/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:50:30 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:51:29 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Intern.hpp"
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern & other);
        Intern& operator=(const Intern& rhs);

        AForm* makeForm(const std::string& form, const std::string target);
        class makeFormException;
    private:
        std::string tolower(std::string& str);
   
};

typedef AForm *(*FormConstructorPtr)(const std::string);

struct form_info 
{
    std::string name;
    FormConstructorPtr f;
};

#endif
