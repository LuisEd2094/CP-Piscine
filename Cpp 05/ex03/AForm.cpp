/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:48:46 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:49:38 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp" 

//Constructor and Deconstructor

AForm::AForm()
    : _name("Default"), 
    _is_signed(false), 
    _grade_to_sign(1), 
    _grade_to_execute(1)
    {}
AForm::~AForm() {}

AForm::AForm(const AForm & other)
    : _name(other._name),
    _is_signed(other._grade_to_sign),
    _grade_to_sign(other._grade_to_sign),
    _grade_to_execute(other._grade_to_execute)
    {}

AForm& AForm::operator=(const AForm & rhs) {
    (void)rhs;
    return (*this);
}

AForm::AForm(std::string name, const int grade_to_sign, const int grade_to_execute)
    : _name(name),
    _is_signed(false),
    _grade_to_sign(grade_to_sign),
    _grade_to_execute(grade_to_execute)
{
    AForm::checkValidGrade(_grade_to_execute);
    AForm::checkValidGrade(_grade_to_sign);
}

//Getters

std::string AForm::getName() const
{
    return (_name);
}
bool AForm::getIsSigned() const
{
    return (_is_signed);
}
int AForm::getGradeToSign() const
{
    return (_grade_to_sign);
}
int AForm::getGradeToExecute() const
{
    return (_grade_to_execute);
}

/// Signing operations

bool AForm::beSigned(const Bureaucrat& signee)
{
    if (_is_signed)
    {
        std::cout << _name << " AForm is already signed!" << std::endl;
        return  (false);
    }
    else if (_grade_to_sign < signee.getGrade())
        throw AForm::GradeTooLowException();
    else
    {
        _is_signed = true;
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
    if (!_is_signed)
        throw AForm::NotSignedException();
    else if (_grade_to_execute < executor.getGrade())
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
