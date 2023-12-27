/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:04:52 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/29 15:08:14 by rude-jes         ###   ########.fr       */
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
	int				i;

	while (*(format++))
	{
		i = 0;
		if (*(format - 1) == '%')
		{
			while (valid_args[i++])
			{
				if (ft_memchr(format, valid_args[i - 1], 1))
					format++;
				if (!valid_args[i - 1])
					return (-1);
			}
		}
	}
	return (1);
}

/*
*	Prints the argument passed to the function
*	Depending on the conversion, the argument is casted to the correct type
*	Then, the argument is converted to a string and printed
*/
static void	printarg(char c, va_list args, int *size)
{
	if (c == 'c')
		ft_putchar_count(va_arg(args, int), size);
	else if (c == 'i' || c == 'd')
		ft_putnbr_count(va_arg(args, int), "0123456789", size);
	else if (c == 's')
		ft_putstr_count(va_arg(args, char *), size);
	else if (c == 'p')
		ft_inttohex((unsigned long int)va_arg(args, void *), size);
	else if (c == 'u')
		ft_putunnbr_count(va_arg(args, unsigned int), "0123456789", size);
	else if (c == 'x')
		ft_putunnbr_count(va_arg(args, unsigned int), "0123456789abcdef", size);
	else if (c == 'X')
		ft_putunnbr_count(va_arg(args, unsigned int), "0123456789ABCDEF", size);
}

/*
*	While the size is not negative, print the string
*	If '%' is found, print the argument with printarg()
*/
static void	print(const char **s, va_list args, int *size)
{
	while (*size >= 0 && *(*s) && *((*s)++) != '%')
		ft_putchar_count(*((*s) - 1), size);
	if (*size >= 0 && *((*s) - 1) == '%')
	{
		if (*(*s) != '%')
			printarg(*((*s)++), args, size);
		else
			ft_putchar_count(*((*s)++), size);
	}
	if (*size < 0)
		return ;
}

int	ft_printf(const char *format, ...)
{
	int		size;
	va_list	args;

	if (check_format(format) < 0)
		return (0);
	size = 0;
	va_start(args, format);
	while (*format && size >= 0)
		print(&format, args, &size);
	va_end(args);
	return (size);
}
