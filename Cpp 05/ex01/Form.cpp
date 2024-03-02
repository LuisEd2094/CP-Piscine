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

class Form::GradeTooHighException : public std::exception
{
    public:
        const char * what() const throw()
        {
            return ("Form: Grade Too High");
        }
};
class Form::GradeTooLowException : public std::exception
{
    public:
        const char * what() const throw()
        {
            return ("Form: Grade Too Low");
        }
};

Form::Form()
    : _name("Default"), 
    _is_signed(false), 
    _grade_to_sign(1), 
    _grade_to_execute(1)
    {}
Form::~Form() {}

Form::Form(const Form & other)
    : _name(other._name),
    _is_signed(other._grade_to_sign),
    _grade_to_sign(other._grade_to_sign),
    _grade_to_execute(other._grade_to_execute)
    {}

Form& Form::operator=(const Form & rhs) {
    (void)rhs;
    return (*this);
}

Form::Form(std::string name, const int grade_to_sign, const int grade_to_execute)
    : _name(name),
    _is_signed(false),
    _grade_to_sign(grade_to_sign),
    _grade_to_execute(grade_to_execute)
{
    Form::checkValidGrade(_grade_to_execute);
    Form::checkValidGrade(_grade_to_sign);
}

//Getters

std::string Form::getName() const
{
    return (_name);
}
bool Form::getIsSigned() const
{
    return (_is_signed);
}
int Form::getGradeToSign() const
{
    return (_grade_to_sign);
}
int Form::getGradeToExecute() const
{
    return (_grade_to_execute);
}

/// Signing operations

bool Form::beSigned(const Bureaucrat& signee)
{
    if (_is_signed)
    {
        std::cout << _name << " form is already signed!" << std::endl;
        return  (false);
    }
    else if (_grade_to_sign < signee.getGrade())
        throw Form::GradeTooLowException();
    else
    {
        _is_signed = true;
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
