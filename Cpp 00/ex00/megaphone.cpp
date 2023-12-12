#include <iostream>
#include <cstdlib>

std::string toUpper(std::string &str)
{

	std::string::iterator it;
	
	for (it = str.begin(); it < str.end(); it++) 
    	*it = std::toupper(*it);
	return (str);
}

int main (int argc, char **argv)
{
	std::string str; 

    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
		for (int i = 1; argv[i]; i++)
		{
 			str = static_cast<std::string>(argv[i]);
			std::cout << toUpper(str);
		}
    }
	std::cout << std::endl;
	exit(EXIT_SUCCESS);
}