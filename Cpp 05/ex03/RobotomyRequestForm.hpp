#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm 
{
    private:
        const std::string m_target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(const std::string& target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm & other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
        
        void execute(const Bureaucrat& executor) const;
};

#endif