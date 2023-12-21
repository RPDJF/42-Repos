/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:49:04 by rude-jes          #+#    #+#             */
/*   Updated: 2023/12/20 14:10:05 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"

int	ft_atoi_base(const char *str, const char *base)
{
	int	output;
	int	sign;
	int	idx;

	output = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign = -sign;
	while (ft_strchr(base, *str) && *ft_strchr(base, *str))
	{
		idx = 0;
		while (base[idx] && *str != base[idx])
			idx++;
		output = output * ft_strlen(base) + idx;
		str++;
	}
	return (sign * output);
}
