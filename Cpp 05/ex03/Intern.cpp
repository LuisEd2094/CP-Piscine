#include "Intern.hpp" 

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern & other) {
    *this = other; 

}

Intern& Intern::operator=(const Intern & rhs) {
    (void)rhs;
    return (*this);
}

std::string Intern::tolower(std::string& str)
{

	std::string::iterator it;
	
	for (it = str.begin(); it < str.end(); it++) 
    	*it = std::tolower(*it);
	return (str);
}


AForm* Intern::makeForm(const std::string& form, const std::string target)
{
    std::string copy = form;
    std::string valid_forms[] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };
    AForm* forms[] = {
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target),
        new ShrubberyCreationForm(target),
    };

    this->tolower(copy);
    for (int i = 0; i < 3; i++)
    {
        if (copy == valid_forms[i])
        {
            return (forms[i]);
        }
    }
    return (NULL);
}
