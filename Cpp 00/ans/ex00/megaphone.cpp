#include <iostream>
#include <cstdlib>

void toUpper(std::string &str)
{
	size_t  i = 0;
	size_t	len = str.length();

	while (i < len)
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
}

int main (int argc, char **argv)
{
	int i = 1;
	std::string str; 

    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
		while (argv[i])
		{
 			str = static_cast<std::string>(argv[i]);
            toUpper(str);
			std::cout << str;
			i++;
		}
    }
	std::cout << std::endl;
	exit(EXIT_SUCCESS);
}