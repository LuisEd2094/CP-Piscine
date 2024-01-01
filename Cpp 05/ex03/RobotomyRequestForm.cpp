/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:50:40 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:51:40 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp" 

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45),  m_target(target) {}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other): AForm(other), m_target(other.m_target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs) {
    (void)rhs;
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat & executor) const
{   
    this->checkValidExecution(executor);
    
    std::srand(std::time(0));
    int random_value = std::rand();

    std::cout << "** DRILLING NOISES **" << std::endl;


    if (random_value % 2 == 0) 
    {
        std::cout << this->m_target << " has been robotomized successfully" << std::endl;
    } else {
        
        std::cout << this->m_target << " was not robotomized!" << std::endl;
    }
}
