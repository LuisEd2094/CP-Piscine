#include "Contact_class.hpp"
#include "PhoneBook_class.hpp"
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
		std::getline(std::cin, str);
		str = remove_white_space(str);
		if (str == "ADD")
			PhoneBook.add();
		else if (str == "SEARCH")
			PhoneBook.search();
        else if (str == "EXIT")
            break;
        else
            PhoneBook.instructions();
	}
    PhoneBook.exit_message();
    exit(EXIT_SUCCESS);
}