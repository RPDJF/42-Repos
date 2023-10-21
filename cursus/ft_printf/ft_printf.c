/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:04:52 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/21 16:15:03 by rude-jes         ###   ########.fr       */
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

static void	printarg(char c, va_list args, int *size)
{
	char	*str;

	str = 0;
	if (c == 'c')
		ft_putchar_count(va_arg(args, int), size);
	else if (c == 'i')
		ft_putchar_count(va_arg(args, int) + '0', size);
	else if (c == 's')
		str = ft_strdup(va_arg(args, char *));
	else if (c == 'p')
		str = ft_strjoin("0x", ft_itoa_base(va_arg(args, int), "0123456789abcdef"));
	else if (c == 'd')
		str = ft_itoa(va_arg(args, int));
	else if (c == 'u')
		str = ft_itoa_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		str = ft_itoa_base(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		str = ft_itoa_base(va_arg(args, int), "0123456789ABCDEF");
	if (str)
	{
		ft_putstr_count(str, size);
		free(str);
		*size += ft_strlen(str);
	}
}

static void	print(const char **str, va_list args, int *size)
{
	while (*(*str) && *((*str)++) != '%')
		ft_putchar_count(*((*str) - 1), size);
	if (*((*str) - 1) == '%')
	{
		if (*(*str) != '%')
			printarg(*((*str)++), args, size);
		else
			ft_putchar_count(*((*str)++), size);
	}
}

int	ft_printf(const char *format, ...)
{
	int		size;
	va_list	args;

	if (check_format(format) < 0)
		return (0);
	size = 0;
	va_start(args, format);
	while (*format)
		print(&format, args, &size);
	va_end(args);
	return (size);
}
