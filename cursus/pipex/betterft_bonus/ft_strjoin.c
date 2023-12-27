/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:04:30 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 16:45:42 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*p;
	size_t	size1;
	size_t	size2;
	size_t	i;
	size_t	j;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	p = (char *)galloc(sizeof(char) * (size1 + size2 + 1));
	if (!p)
		return (0);
	i = 0;
	while (i < size1)
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < size2)
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = 0;
	return (p);
}
