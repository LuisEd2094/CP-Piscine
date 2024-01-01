/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:45:48 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:45:50 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
    public:
        //Constructor and Deconstructor
        Form();
        ~Form();
        Form(const Form & other);
        Form& operator=(const Form& rhs);
        Form(std::string name, const int grade_to_sign, const int grade_to_execute);

        //Getters

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        bool beSigned(const Bureaucrat& signee);


        class GradeTooHighException : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return ("Form: Grade Too High");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return ("Form: Grade Too Low");
                }
        };
    private:
        const std::string m_name;
        bool m_is_signed;
        const int m_grade_to_sign;
        const int m_grade_to_execute;
        void checkValidGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const Form& rhs);


#endif
