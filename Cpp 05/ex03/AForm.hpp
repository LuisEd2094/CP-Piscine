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

#ifndef AFOR_HPP
# define AFOR_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string _name;
        bool _is_signed;
        const int _grade_to_sign;
        const int _grade_to_execute;
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
        class GradeTooHighException;
        class GradeTooLowException;
        class NotSignedException;
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);


#endif
