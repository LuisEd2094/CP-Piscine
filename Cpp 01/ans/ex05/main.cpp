#include "Harl.hpp"
#include <iostream>
#include <string>

int main(void)
{
    Harl harl;
    std::string complains[4]  = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};

    for (int i = 0; i < 4; i++){
        std::cout << complains[i] << ": " << std::endl;
        harl.complain(complains[i]);
    }
    return (0);

}