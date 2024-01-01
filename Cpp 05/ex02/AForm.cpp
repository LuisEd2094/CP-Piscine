/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:46:13 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:46:14 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp" 


//Constructor and Deconstructor

AForm::AForm()
    : m_name("Default"), 
    m_is_signed(false), 
    m_grade_to_sign(1), 
    m_grade_to_execute(1)
    {}
AForm::~AForm() {}

AForm::AForm(const AForm & other)
    : m_name(other.m_name),
    m_is_signed(other.m_grade_to_sign),
    m_grade_to_sign(other.m_grade_to_sign),
    m_grade_to_execute(other.m_grade_to_execute)
    {}

AForm& AForm::operator=(const AForm & rhs) {
    (void)rhs;
    return (*this);
}

AForm::AForm(std::string name, const int grade_to_sign, const int grade_to_execute)
    : m_name(name),
    m_is_signed(false),
    m_grade_to_sign(grade_to_sign),
    m_grade_to_execute(grade_to_execute)
{
    AForm::checkValidGrade(this->m_grade_to_execute);
    AForm::checkValidGrade(this->m_grade_to_sign);
}

//Getters

std::string AForm::getName() const
{
    return (this->m_name);
}
bool AForm::getIsSigned() const
{
    return (this->m_is_signed);
}
int AForm::getGradeToSign() const
{
    return (this->m_grade_to_sign);
}
int AForm::getGradeToExecute() const
{
    return (this->m_grade_to_execute);
}

/// Signing operations

bool AForm::beSigned(const Bureaucrat& signee)
{
    if (this->m_is_signed)
    {
        std::cout << this->m_name << " AForm is already signed!" << std::endl;
        return  (false);
    }
    else if (this->m_grade_to_sign < signee.getGrade())
        throw AForm::GradeTooLowException();
    else
    {
        this->m_is_signed = true;
        return (true);
    }
}

///Helpers

void AForm::checkValidGrade(int grade)
{
    if (grade < 1)
        throw AForm::GradeTooHighException();
    if (grade > 150)
        throw AForm::GradeTooLowException();
}

void AForm::checkValidExecution(const Bureaucrat & executor) const
{
    if (!this->m_is_signed)
        throw AForm::NotSignedException();
    else if (this->m_grade_to_execute < executor.getGrade())
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs)
{
    os << rhs.getName() <<" AForm";
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
