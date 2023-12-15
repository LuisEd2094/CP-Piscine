#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

void testPresidential()
{
    //Needs sign 25, exec 5
    PresidentialPardonForm form("Ford");
    Bureaucrat signee("Bureaucrat", 24);

    try
    {
        form.execute(signee);
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