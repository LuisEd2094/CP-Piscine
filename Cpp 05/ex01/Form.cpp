/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:45:45 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:45:45 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp" 


//Constructor and Deconstructor

Form::Form()
    : m_name("Default"), 
    m_is_signed(false), 
    m_grade_to_sign(1), 
    m_grade_to_execute(1)
    {}
Form::~Form() {}

Form::Form(const Form & other)
    : m_name(other.m_name),
    m_is_signed(other.m_grade_to_sign),
    m_grade_to_sign(other.m_grade_to_sign),
    m_grade_to_execute(other.m_grade_to_execute)
    {}

Form& Form::operator=(const Form & rhs) {
    (void)rhs;
    return (*this);
}

Form::Form(std::string name, const int grade_to_sign, const int grade_to_execute)
    : m_name(name),
    m_is_signed(false),
    m_grade_to_sign(grade_to_sign),
    m_grade_to_execute(grade_to_execute)
{
    Form::checkValidGrade(this->m_grade_to_execute);
    Form::checkValidGrade(this->m_grade_to_sign);
}

//Getters

std::string Form::getName() const
{
    return (this->m_name);
}
bool Form::getIsSigned() const
{
    return (this->m_is_signed);
}
int Form::getGradeToSign() const
{
    return (this->m_grade_to_sign);
}
int Form::getGradeToExecute() const
{
    return (this->m_grade_to_execute);
}

/// Signing operations

bool Form::beSigned(const Bureaucrat& signee)
{
    if (this->m_is_signed)
    {
        std::cout << this->m_name << " form is already signed!" << std::endl;
        return  (false);
    }
    else if (this->m_grade_to_sign < signee.getGrade())
        throw Form::GradeTooLowException();
    else
    {
        this->m_is_signed = true;
        return (true);
    }
}

///Helpers

void Form::checkValidGrade(int grade)
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& rhs)
{
    os << rhs.getName() <<" form";
    os << std::endl;
    os << "Signed status: ";
    if (rhs.getIsSigned())
        os << "Signed";
    else
        os << "Not Signed";
    os << std::endl;
    os << "Grade required to sign: " << rhs.getGradeToSign() << std::endl;
    os << "Grade requiered to execute: " << rhs.getGradeToExecute() << std::endl;

    return (os);
}
