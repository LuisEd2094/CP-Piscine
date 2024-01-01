/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoto-do <lsoto-do@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:48:02 by lsoto-do          #+#    #+#             */
/*   Updated: 2024/01/01 10:48:05 by lsoto-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm 
{
    private:
        const std::string m_target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(const std::string& target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm & other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
        
        void execute(const Bureaucrat& executor) const;
};

#endif
