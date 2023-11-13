/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:49:04 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 21:02:49 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"

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
