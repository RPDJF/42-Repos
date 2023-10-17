/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:49:04 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/13 09:52:30 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Converts the initial portion of the string pointed to by str to int
** representation.
*/

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	output;
	int	sign;

	output = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign = -sign;
	while (ft_isdigit(*str))
		output = output * 10 + *(str++) - '0';
	return (sign * output);
}

/*#include <stdio.h>

int main(void)
{
	char test[] = "0x123";
	printf("FT: %d\nReal: %d\n", ft_atoi(test), atoi(test));
}
*/