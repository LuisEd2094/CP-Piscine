/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:48:18 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:48:19 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp" 

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137),  m_target(target) {}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other): AForm(other), m_target(other.m_target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs) {
    (void)rhs;
    return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{  
    this->checkValidExecution(executor);
    
    std::string file = this->m_target + "_shrubbery";
    const char *file_name = file.c_str();
    std::ofstream output_file(file_name);

    if (output_file.is_open())
    {
        output_file << "      *      " << std::endl;
        output_file << "     / \\     " << std::endl;
        output_file << "    /   \\    " << std::endl;
        output_file << "   /     \\   " << std::endl;
        output_file << "  /       \\  " << std::endl;
        output_file << " /         \\ " << std::endl;
        output_file << "*************" << std::endl;
        output_file << "     |||     " << std::endl;
        output_file << "     |||     " << std::endl;
        output_file << "     |||     " << std::endl;
        output_file << "     |||     " << std::endl;

        output_file.close();
    }
    else
    {
        std::cerr << "couldn't open file :" << file_name << std::endl;
    }

}
