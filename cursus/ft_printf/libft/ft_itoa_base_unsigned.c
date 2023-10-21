/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:09:26 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/21 18:09:26 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_unsigned(unsigned long int n, const char *base)
{
	char				*p;
	unsigned long int	temp;
	size_t				len;

	temp = n;
	len = 0;
	while (++len, temp >= ft_strlen(base))
		temp /= ft_strlen(base);
	p = (char *)ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (0);
	temp = n;
	while (len-- > 0)
	{
		p[len] = base[temp % ft_strlen(base)];
		temp /= ft_strlen(base);
	}
	return (p);
}
