#include "ShrubberyCreationForm.hpp" 

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137),  m_target(target) {}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & other): AForm(other), m_target(other.m_target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm & rhs) {
    (void)rhs;
    return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{  
    this->checkValidExecution(executor);
    
    std::string file = this->m_target + "_shrubbery";
    const char *file_name = file.c_str();
    std::ofstream output_file(file_name);

    if (output_file.is_open())
    {
        output_file << "      *      " << std::endl;
        output_file << "     / \\     " << std::endl;
        output_file << "    /   \\    " << std::endl;
        output_file << "   /     \\   " << std::endl;
        output_file << "  /       \\  " << std::endl;
        output_file << " /         \\ " << std::endl;
        output_file << "*************" << std::endl;
        output_file << "     |||     " << std::endl;
        output_file << "     |||     " << std::endl;
        output_file << "     |||     " << std::endl;
        output_file << "     |||     " << std::endl;

        output_file.close();
    }
    else
    {
        std::cerr << "couldn't open file :" << file_name << std::endl;
    }

}