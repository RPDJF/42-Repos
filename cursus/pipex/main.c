#include <stdio.h>
#include "betterft/betterft.h"

static size_t	charcount(char c, char *str)
{
	size_t	count;

	printf("start\n");
	count = 0;
	while (str && *str)
	{
		printf("iter\n");
		if (ft_strchr(str, c))
		{
			str = ft_strchr(str, c) + 1;
			count++;
		}
		else
			break ;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	size_t nbquote;

	nbquote = charcount('\'', argv[1]);
	printf("%zu\n", nbquote);
	nbquote -= nbquote % 2;
	nbquote /= 2;
	printf("%zu\n", nbquote);
}
