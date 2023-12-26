#include "Bureaucrat.hpp" 
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : m_name("default"), m_grade(150){}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name)
{
    if (grade > 0 && grade <= 150)
        this->m_grade = grade;
    else
    {
        if (grade <= 0)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
    }

}
Bureaucrat::Bureaucrat(const Bureaucrat & other) : m_name(other.m_name), m_grade(other.m_grade) {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat & rhs) {
    if (this != &rhs)
    {
        this->m_grade = rhs.m_grade;
    }
    return (*this);
}

void Bureaucrat::incrementGrade()
{
    if (this->m_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    else 
        this->m_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->m_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    else 
        this->m_grade++;
}

std::string Bureaucrat::getName() const{
    return (this->m_name);
}

int Bureaucrat::getGrade() const{
    return (this->m_grade);
}

void Bureaucrat::signAForm(AForm& AForm) const
{
    try
    {
        if (AForm.beSigned(*this))
            std::cout << this->m_name << " signed AForm: " << AForm.getName() << std::endl;
        else
            std::cerr << this->m_name << " couldn't sign AForm: " << AForm.getName() << " since it's already signed!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->m_name << " couldn't sign AForm: " << e.what() << std::endl;
    }
} 

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->m_name << " executed: " << form.getName() << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }    
}




std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
    os << rhs.getName()<<", bureaucrat grade " << rhs.getGrade() << "." << std::endl;

    return (os);
}