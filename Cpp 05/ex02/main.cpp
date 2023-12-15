#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void testPresidential()
{
    //Needs sign 25, exec 5
    PresidentialPardonForm form("Ford");
    Bureaucrat tooLowSignee("Hermes", 26);
    Bureaucrat signee("Bureaucrat", 24);
    Bureaucrat executor("Executor", 5);

    tooLowSignee.signAForm(form);
    signee.signAForm(form);
    signee.executeForm(form);
    executor.executeForm(form);

}

void testShrubbery()
{
    // sign 72, exc 45
    ShrubberyCreationForm form("House");
    Bureaucrat tooLowSignee("Hermes", 150);
    Bureaucrat signee("Bureaucrat", 139);
    Bureaucrat executor("Executor", 130);
    
    tooLowSignee.signAForm(form);
    signee.signAForm(form);
    signee.executeForm(form);
    executor.executeForm(form);

}

void testRobotomy()
{
    //sign 72, exec 45
    RobotomyRequestForm form("Melvin");
    Bureaucrat tooLowSignee("Hermes", 150);
    Bureaucrat signee("Bureaucrat", 72);
    Bureaucrat executor("Executor", 45);
    
    tooLowSignee.signAForm(form);
    signee.signAForm(form);
    signee.executeForm(form);
    executor.executeForm(form);

}

int main()
{
    testPresidential();
    testShrubbery();
    testRobotomy();
}