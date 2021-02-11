#include <iostream>

std::string touppercase(std::string str)
{
	size_t i = 0;
	while (i < str.length())
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int main(int argc, char *argv[])
{
	int i;

	i = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (++i < argc)
		{
			std::cout <<  touppercase(argv[i]);
		}
	}
	std::cout << "\n";
}
