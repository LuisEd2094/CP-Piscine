/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:50:18 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:50:20 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string m_name;
        bool m_is_signed;
        const int m_grade_to_sign;
        const int m_grade_to_execute;
        void checkValidGrade(int grade);
        AForm();
    public:
        //Constructor and Deconstructor
        virtual ~AForm();
        AForm(const AForm & other);
        AForm& operator=(const AForm& rhs);
        AForm(std::string name, const int grade_to_sign, const int grade_to_execute);
        //Getters

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        bool beSigned(const Bureaucrat& signee);
        void checkValidExecution(const Bureaucrat& executor) const;
        virtual void execute(const Bureaucrat & executor) const = 0;
        class GradeTooHighException : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return ("AForm: Grade Too High");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return ("AForm: Grade Too Low");
                }
        };
        class NotSignedException : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return ("AForm: Form not signed");
                }
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);


#endif
