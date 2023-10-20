/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:04:52 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/20 17:55:59 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
*	Check the format input
*	If '%' is found, check if following char is a valid conversion
*
*	Returns count of VA_LIST if format is valid
*	Returns	-1 if format is invalid
*/
int	check_format(const char *format)
{
	const char		valid_args[] = "cspdiuxX%%";
	int				output;
	int				i;

	output = 0;
	while (*(format++))
	{
		i = 0;
		if (*(format - 1) == '%')
		{
			while (valid_args[i++])
			{
				if (ft_memchr(format, valid_args[i - 1], 1))
				{
					format++;
					if (*format != '%')
						output++;
					break ;
				}
				if (!valid_args[i])
					return (-1);
			}
		}
	}
	return (1);
}

static int	printarg(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, char), 1);
	if (c == 'c')
		return (1);
	if (c == 'i')
		ft_putnbr_fd(va_arg(args, char), 1);
	if (c == 'i')
		// return size
}

#include <stdio.h>

static void	print(const char **str, va_list args)
{
	while (*(*str) && *((*str)++) != '%')
		ft_putchar_fd(*((*str) - 1), 1);
	if (*((*str) - 1) == '%')
	{
		if (*(*str) != '%')
		{
			printarg(*(*str), args);
			(*str)++;
		}
		else
			ft_putchar_fd(*(*str++), 1);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	if (check_format(format) < 0)
		return (0);
	va_start(args, format);
	while (*format)
		print(&format, args);
	va_end(args);
	return (1);
}

int	main(int argc, char **argv)
{
	//printf("hello %%\n");
	ft_printf(argv[1], 'x', 'z');
}
