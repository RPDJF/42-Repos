/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:10:58 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/13 12:10:58 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free2dmalloc(void **m, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(m[i++]);
}

#include <stdio.h>

int	splitentriescount(char const *s, char c)
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

char	**ft_split(char const *s, char c)
{
	char		**p;
	const char	*sreader;
	size_t		entries;
	size_t		i;
	size_t		j;

	if (!s)
		return (0);
	else if (!ft_strlen(s) || !c)
	{
		p = (char **)malloc(sizeof(char *));
		p[0] = 0;
		return(p);
	}
	if (!ft_strlen(s))
		return (0);
	entries = splitentriescount(s, c);
	p = (char **)malloc((entries + 1) * sizeof(char *));
	if (!p)
		return (0);
	i = 0;
	sreader = s;
	while (i < entries)
	{
		j = 0;
		while (*(sreader++) && *(sreader - 1) != c)
			j++;
		if (j == 0)
			continue;
		p[i] = (char *)ft_calloc(j + 1, sizeof(char));
		if (!p[i])
		{
			free2dmalloc((void **)p, i);
			return (0);
		}
		ft_memmove(p[i], sreader - 1 - j, j);
		i++;
	}
	p[i] = 0;
	return (p);
}

// test ft_split function with multiple parameters
//#include <stdio.h>
/*#include <stdlib.h>
#include <string.h>

int main(void)
{
	// do code
	char	**p;
	char	*s;
	char	c;

	s = "split  ||this|for|me|||||!|";
	c = '|';
	p = ft_split(s, c);
	printf("%s\n", p[0]);
	printf("%s\n", p[1]);
	printf("%s\n", p[2]);
	printf("%s\n", p[3]);
	printf("%s\n", p[4]);
	free2dmalloc((void **)p, 5);
	free(p);
}
*/