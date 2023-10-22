#include "ft_printf.h"

int main(void)
{
	char *str = "salut";
	int i = printf("test [%s]\n", str);
	printf("i [%d]\n", i);
	i = ft_printf("test [%s]\n", str);
	printf("i [%d]\n", i);
	return (0);
}
