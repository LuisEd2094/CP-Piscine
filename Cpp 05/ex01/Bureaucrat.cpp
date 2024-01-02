/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:45:38 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:45:39 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" 
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150){}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade > 0 && grade <= 150)
        _grade = grade;
    else
    {
        if (grade <= 0)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
    }

}
Bureaucrat::Bureaucrat(const Bureaucrat & other) : _name(other._name), _grade(other._grade) {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat & rhs) {
    if (this != &rhs)
    {
        _grade = rhs._grade;
    }
    return (*this);
}

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    else 
        _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    else 
        _grade++;
}

std::string Bureaucrat::getName() const{
    return (_name);
}

int Bureaucrat::getGrade() const{
    return (_grade);
}

void Bureaucrat::signForm(Form& form) const
{
    try
    {
        if (form.beSigned(*this))
            std::cout << _name << " signed form: " << form.getName() << std::endl;
        else
            std::cerr << _name << " couldn't sign form: " << form.getName() << " since it's already signed!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << _name << " couldn't sign form: " << e.what() << std::endl;
    }
} 



std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
    os << rhs.getName()<<", bureaucrat grade " << rhs.getGrade() << "." << std::endl;

    return (os);
}

