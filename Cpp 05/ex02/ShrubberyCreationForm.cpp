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

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137),  _target(target) {}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other): AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs) {
    (void)rhs;
    return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{  
    checkValidExecution(executor);
    
    std::string file = _target + "_shrubbery";
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
