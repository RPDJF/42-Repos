/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:04:52 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/20 10:37:04 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


/*
*	Check the format input
*	If '%' is found, check if following char is a valid conversion
*
*	Returns 2 if valid and doesn't contain any conversion
*	Returns 1 if format is valid
*	Returns	0 if format is invalid
*/
int	check_format(const char *format)
{
	const char	valid_args = "cspdiuxX%%";
	int			trigger;

	trigger = 0;
	while (*(format++))
	{
		if (*(format - 1) == '%' && ft_strnstr(format, valid_args))
		{
			if (*format != '%')
				trigger = 1;
			format++;
		}
		else
			return (0);
	}
	if (trigger)
		return (1);
	return (2);
}

int	ft_printf(const char *format, ...)
{
	if (!check_format(format))
		return (0);
}

int	main(void)
{
	printf("hello %%\n");
}
