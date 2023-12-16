#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"


class ShrubberyCreationForm : public AForm 
{
    private:
        const std::string m_target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(const std::string& target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm & other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
        
        void execute(const Bureaucrat& executor) const;
};

#endif