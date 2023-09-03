#include "Contact_class.hpp"
#include "PhoneBook_class.hpp"

int main(void)
{

	PhoneBook 	PhoneBook;
	std::string	str ="";

    PhoneBook.welcome_message();
    PhoneBook.instructions();
	while (1)
	{
		std::cout << "Enter a command > ";
		std::getline(std::cin, str);
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
	return (0);
}