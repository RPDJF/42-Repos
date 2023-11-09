/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:10:58 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 18:10:15 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"

size_t	ft_countwords(char const *s, char c)
{
	size_t	entries;
	int		trigger;

	entries = 0;
	trigger = 0;
	while (*(s++))
	{
		if (*(s - 1) != c && !trigger)
		{
			entries++;
			trigger = 1;
		}
		else if (*(s - 1) == c)
			trigger = 0;
	}
	return (entries);
}

int	pushwords(char **dst, char const *src, char c)
{
	size_t	i;
	size_t	j;
	size_t	entries;

	entries = ft_countwords(src, c);
	i = 0;
	while (i < entries)
	{
		j = 0;
		while (*(src++) && *(src - 1) != c)
			j++;
		if (j == 0)
			continue ;
		dst[i] = (char *)ft_calloc(j + 1, sizeof(char));
		if (!dst[i])
		{
			ft_memsuperclear((void **)dst, i + 1);
			return (1);
		}
		ft_memmove(dst[i], src - 1 - j, j);
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char		**p;
	size_t		entries;

	if (!s || !*s)
		return ((char **)ft_calloc(1, sizeof(char *)));
	entries = ft_countwords(s, c);
	if (!entries)
	{
		p = (char **)ft_calloc(1, sizeof(char *));
		return (p);
	}
	p = (char **)ft_calloc(entries + 1, sizeof(char *));
	if (!p)
		return (0);
	if (pushwords(p, s, c))
		return (0);
	p[entries] = 0;
	return (p);
}
