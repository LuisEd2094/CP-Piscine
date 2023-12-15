#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

void testPresidential()
{
    //Needs sign 25, exec 5
    PresidentialPardonForm form("Ford");
    Bureaucrat tooLowSignee("Too low", 26);
    Bureaucrat signee("Bureaucrat", 24);
    Bureaucrat executor("Executor", 5);

    try
    {
        form.execute(signee);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        tooLowSignee.signAForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        signee.signAForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        form.beSigned(signee);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        form.execute(executor);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    
}


int main()
{
    testPresidential();
}