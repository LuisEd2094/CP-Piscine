#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Form
{
    public:
        Form();
        ~Form();
        Form(const Form & other);
        Form& operator=(const Form& rhs);
    private:
};

#endif