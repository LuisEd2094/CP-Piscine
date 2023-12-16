#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Intern.hpp"
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern & other);
        Intern& operator=(const Intern& rhs);

        AForm* makeForm(const std::string& form, const std::string target);
    private:
        std::string tolower(std::string& str);
};

#endif