/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_un.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:03:30 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/22 14:00:06 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_un(unsigned int n)
{
	char			*p;
	unsigned int	temp;
	int				len;

	temp = n;
	len = 0;
	while (++len, temp >= 10)
		temp /= 10;
	p = (char *)ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (0);
	temp = n;
	while (len-- > 0)
	{
		p[len] = (temp % 10) + '0';
		temp /= 10;
	}
	return (p);
}
