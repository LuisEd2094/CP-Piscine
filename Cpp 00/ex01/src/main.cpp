#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "ft_lib.hpp"


int main(int argc, char **argv)
{

	PhoneBook 	PhoneBook;
	std::string	str ="";

    if (argc > 1 && argv)
        exit(EXIT_SUCCESS);
    PhoneBook.welcome_message();
    PhoneBook.instructions();
	while (1)
	{
		std::cout << "Enter a command > ";
		get_new_input(str);
		if (std::cin.eof() == 1)
			PhoneBook.exit_program();
		if (str == "ADD")
			PhoneBook.add();
		else if (str == "SEARCH")
			PhoneBook.search();
        else if (str == "EXIT")
            break;
        else
            PhoneBook.instructions();
	}
    PhoneBook.exit_program();
}