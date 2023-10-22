/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:04:52 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/22 14:50:50 by rude-jes         ###   ########.fr       */
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

static void	printarg(char c, va_list args, int *size)
{
	void		*s;
	char		nu;

	nu = -1;
	s = &nu;
	if (c == 'c')
		ft_putchar_count(va_arg(args, int), size);
	else if (c == 'i' || c == 'd')
		s = ft_itoa(va_arg(args, int));
	else if (c == 's')
		ft_putstr_count(va_arg(args, char *), size);
	else if (c == 'p')
		s = ft_inttohex((unsigned long int)va_arg(args, void *));
	else if (c == 'u')
		s = ft_itoa_un(va_arg(args, unsigned int));
	else if (c == 'x')
		s = ft_itoa_base_un(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		s = ft_itoa_base_un(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (!s)
		*size = -1;
	if (s && *(char *)s != -1)
		ft_putstr_count((char *)s, size);
	if (s && *(char *)s != -1)
		free(s);
}

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
