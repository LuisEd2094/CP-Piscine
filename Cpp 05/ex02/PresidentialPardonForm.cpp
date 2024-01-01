/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:47:56 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:47:58 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp" 

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5),  m_target(target) {}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & other): AForm(other), m_target(other.m_target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm & rhs) {
    (void)rhs;
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const
{
    this->checkValidExecution(executor);
    std::cout << this->m_target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
