#include <iostream>
#include <cstdlib>
/*
int	main(int argc, char **argv)
{
	int		i;
	int		j;

	j = -1;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argc > 1 && argv && argv[++j])
	{
		i = -1;
		while (j > 0 && argv[j][++i])
			std::cout << (char)std::toupper(argv[j][i]);
	}
	std::cout << std::endl;
	return (0);
}*/

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

    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
		while (argv[i])
		{
            std::string str = static_cast<std::string>(argv[i]);
            toUpper(str);
			std::cout << str;
			i++;
		}
    }
	std::cout << std::endl;
	exit(EXIT_SUCCESS);
}