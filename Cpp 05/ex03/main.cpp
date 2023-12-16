#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


void interTest()
{
    Intern intern;

    AForm *form = intern.makeForm("robotomy request", "Bender");

    std::cout << *form;
}

int main()
{
    interTest();
}