/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:45:20 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:45:21 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp" 

Bureaucrat::Bureaucrat() : m_name("default"), m_grade(150){}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name)
{
    if (grade > 0 && grade <= 150)
        this->m_grade = grade;
    else
    {
        if (grade <= 0)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
    }

}
Bureaucrat::Bureaucrat(const Bureaucrat & other) : m_name(other.m_name), m_grade(other.m_grade) {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat & rhs) {
    if (this != &rhs)
    {
        this->m_grade = rhs.m_grade;
    }
    return (*this);
}

void Bureaucrat::incrementGrade()
{
    if (this->m_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    else 
        this->m_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->m_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    else 
        this->m_grade++;
}

std::string Bureaucrat::getName() const{
    return (this->m_name);
}

int Bureaucrat::getGrade() const{
    return (this->m_grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
    os << rhs.getName()<<", bureaucrat grade " << rhs.getGrade() << "." << std::endl;

    return (os);
}
