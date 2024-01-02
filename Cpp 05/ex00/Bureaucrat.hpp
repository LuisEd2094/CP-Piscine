/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:45:24 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:45:25 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat & other);
        Bureaucrat& operator=(const Bureaucrat& rhs);

        std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

	    class GradeTooHighException : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return ("Grade Too High");
                }
        };

        class GradeTooLowException : public std::exception
	    {
        public:
            const char* what() const throw()
            {
                return ("Grade too low");
            }
        };

    private:
        const std::string _name;
        int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif
