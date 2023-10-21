/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:04:31 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/21 19:04:31 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	// check if the ft_printf function works, do tests with the real printf with cspdiuxX%%

	ft_printf("\nTest 1\n");
	printf("%d\n", printf("Hello world\n"));
	printf("%d\n", ft_printf("Hello world\n"));

	ft_printf("\nTest 2\n");
	printf("%d\n", printf("Hello %s\n", "world"));
	printf("%d\n", ft_printf("Hello %s\n", "world"));

	ft_printf("\nTest 3\n");
	printf("%d\n", printf("Hello %c\n", 'w'));
	printf("%d\n", ft_printf("Hello %c\n", 'w'));

	ft_printf("\nTest 4\n");
	char *str = "world";
	printf("%d\n", printf("Hello %p\n", &str));
	printf("%d\n", ft_printf("Hello %p\n", &str));

	ft_printf("\nTest 5\n");
	printf("%d\n", printf("Hello %i\n", 42));
	printf("%d\n", ft_printf("Hello %i\n", 42));

	ft_printf("\nTest 6\n");
	printf("%d\n", printf("Hello %d\n", 42));
	printf("%d\n", ft_printf("Hello %d\n", 42));

	ft_printf("\nTest 7\n");
	printf("%d\n", printf("Hello %u\n", 42));
	printf("%d\n", ft_printf("Hello %u\n", 42));

	ft_printf("\nTest 8\n");
	printf("%d\n", printf("Hello %x\n", 42));
	printf("%d\n", ft_printf("Hello %x\n", 42));

	ft_printf("\nTest 9\n");
	printf("%d\n", printf("Hello %X\n", 42));
	printf("%d\n", ft_printf("Hello %X\n", 42));

	ft_printf("\nTest 10\n");
	printf("%d\n", printf("Hello %%\n"));
	printf("%d\n", ft_printf("Hello %%\n"));

	ft_printf("\nTest 11\n");
	printf("%d\n", printf("Hello %c %s %p %i %d %u %x %X %%\n", 'w', "world", &str, 42, 42, 42, 42, 42));
	printf("%d\n", ft_printf("Hello %c %s %p %i %d %u %x %X %%\n", 'w', "world", &str, 42, 42, 42, 42, 42));

	ft_printf("\nTest 12\n");
	printf("%d\n", printf("%cs%cs%c\n", 'c', 'b', 'a'));
	printf("%d\n", ft_printf("%cs%cs%c\n", 'c', 'b', 'a'));

	ft_printf("\nTest 13\n");
	printf("%d\n", printf("%c%c%c", 'a', '\t', 'b'));
	printf("%d\n", ft_printf("%c%c%c", 'a', '\t', 'b'));

	return (0);
}
