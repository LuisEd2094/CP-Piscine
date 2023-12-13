#include "Bureaucrat.hpp"
#include "Form.hpp"

void upAndDownTest()
{
    Bureaucrat john("John", 2);
	Bureaucrat jim("Jim", 149);

	try
	{
		std::cout << john << std::endl;
		std::cout << jim << std::endl;
		john.incrementGrade();
		jim.decrementGrade();
		std::cout << john << std::endl;
		std::cout << jim << std::endl;
		john.incrementGrade();
		jim.decrementGrade();
		std::cout << john << std::endl;
		std::cout << jim << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void creationTest()
{
    try
    {
        Bureaucrat john("John", 999999999);
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat john("John", -999999999);
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    Bureaucrat john;

    std::cout << john;
}

void formExceptionTest()
{
    try
    {
        Form form3("Vacation Request", 151, 0);
        std::cout << form3;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form form4("Vacation Request", 0, 151);
        std::cout << form4;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    

  
}

void validFormTest()
{
    try
    {
        Form form;
        Form form2("Vacation Request", 50, 50);
        
        std::cout << form;
        std::cout << form2;  

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void signFormTest()
{
    Form form("Vacation Request", 50, 50);
    Form form2("Time off request", 50, 50);
    Bureaucrat john("John", 1);
    Bureaucrat alice("Alice", 150);

    try
    {
        form.beSigned(john);
        std::cout << form;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        form.beSigned(alice);
        std::cout << form;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        form2.beSigned(alice);
        std::cout << form;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}

void burocratSignTest()
{
    Form form;
    Form form2("Holidays", 50, 50);
    Form form3("Off", 150, 150);
    Bureaucrat john("John", 49);

    john.signForm(form);
    john.signForm(form2);
    john.signForm(form3);
    john.signForm(form2);
    john.signForm(form3);

}
int main()
{
//    upAndDownTest();
//    creationTest();
//    formExceptionTest();
//    validFormTest();
//     signFormTest();
    burocratSignTest();
}