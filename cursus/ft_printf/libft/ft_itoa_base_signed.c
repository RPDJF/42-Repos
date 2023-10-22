/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_signed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:04:12 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/22 11:23:05 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_signed(int n, char *base)
{
	char			*p;
	unsigned int	temp;
	int				len;

	p = ft_calloc(9, sizeof(char));
	if (!p)
		return (0);
	p[8] = 0;
	if (n >= 0)
		return (ft_itoa_base(n, base));
	len = 8;
	while (len-- > 0)
		p[len] = base[ft_strlen(base) - 1];
	temp = -n;
	len = 0;
	while (++len, temp >= ft_strlen(base))
		temp /= ft_strlen(base);
	temp = -n;
	while (len-- > 0)
	{
		p[8 - len - 1] = base[ft_strlen(base) - (temp % ft_strlen(base))];
		temp /= ft_strlen(base);
	}
	return (p);
}
