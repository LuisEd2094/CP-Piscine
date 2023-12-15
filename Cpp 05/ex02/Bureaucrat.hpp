#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class AForm;

class Bureaucrat
{
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat & other);
        Bureaucrat& operator=(const Bureaucrat& rhs);

        std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        void signAForm(AForm& form) const;

	    class GradeTooHighException : public std::exception
        {
            public:
                const char * what() const throw()
                {
                    return ("Grade Too High");
                }
        };

        class GradeTooLowException : public std::exception
	    {
        public:
            const char* what() const throw()
            {
                return ("Grade too low");
            }
        };

    private:
        const std::string m_name;
        int m_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif