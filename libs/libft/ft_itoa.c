/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:04:38 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/20 12:55:15 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	inputparser(int n)
{
	unsigned int	output;

	if (n < 0)
		output = -n;
	else
		output = n;
	return (output);
}

char	*ft_itoa(int n)
{
	char			*p;
	unsigned int	temp;
	int				isneg;
	int				len;

	isneg = 0;
	if (n < 0)
		isneg = 1;
	temp = inputparser(n);
	len = 0;
	while (++len, temp >= 10)
		temp /= 10;
	p = (char *)ft_calloc(len + 1 + isneg, sizeof(char));
	if (!p)
		return (0);
	temp = inputparser(n);
	while (len-- > 0)
	{
		p[len + isneg] = (temp % 10) + '0';
		temp /= 10;
	}
	if (isneg)
		p[0] = '-';
	return (p);
}
