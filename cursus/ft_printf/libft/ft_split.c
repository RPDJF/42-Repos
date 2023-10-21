/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:10:58 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/15 18:43:04 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free2dmalloc(void **m, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
}

size_t	splitentriescount(char const *s, char c)
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

	entries = splitentriescount(src, c);
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
			free2dmalloc((void **)dst, i + 1);
			return (1);
		}
		ft_memmove(dst[i], src - 1 - j, j);
		i++;
	}
	return (0);
}

//#include <stdio.h>
char	**ft_split(char const *s, char c)
{
	char		**p;
	size_t		entries;

	if (!s || !*s)
		return ((char **)ft_calloc(1, sizeof(char *)));
	entries = splitentriescount(s, c);
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

// test ft_split function with multiple parameters
/*
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char **p;
	int	i;

	printf("test 1\nft_split(\"Bonjour\", 0)\n");
	p = ft_split("Bonjour", '\0');
	i = 0;
	while (p[i])
	{
		printf("[%d]\t%s\n", i,  p[i]);
		i++;
	}
	free2dmalloc((void **)p, i);
	printf("\n");

	printf("test 1\nft_split(\"Bonjour\", 0)\n");
	p = ft_split("Bonjour", 0);
	i = 0;
	while (p[i])
	{
		printf("[%d]\t%s\n", i,  p[i]);
		i++;
	}
	free2dmalloc((void **)p, i);
	printf("\n");
	
	printf("test 2\nft_split(\"Bonjour\", 'o')\n");
	p = ft_split("Bonjour", 'o');
	i = 0;
	while (p[i])
	{
		printf("[%d]\t%s\n", i,  p[i]);
		i++;
	}
	free2dmalloc((void **)p, i);
	printf("\n");

	printf("test 3\nft_split(\"Bonjour\", 'B')\n");
	p = ft_split("Bonjour", 'B');
	i = 0;
	while (p[i])
	{
		printf("[%d]\t%s\n", i,  p[i]);
		i++;
	}
	free2dmalloc((void **)p, i);
	printf("\n");

	printf("test 4\nft_split(\"Bonjour\", 'r')\n");
	p = ft_split("Bonjour", 'r');
	i = 0;
	while (p[i])
	{
		printf("[%d]\t%s\n", i,  p[i]);
		i++;
	}
	free2dmalloc((void **)p, i);
	printf("\n");

	printf("test 5\nft_split(\"\", 'B')\n");
	p = ft_split("", 'B');
	i = 0;
	while (p[i])
	{
		printf("[%d]\t%s\n", i,  p[i]);
		i++;
	}
	free2dmalloc((void **)p, i);
	printf("\n");

	printf("test 6\nft_split(\"\", 0)\n");
	p = ft_split("", 0);
	i = 0;
	while (p[i])
	{
		printf("[%d]\t%s\n", i,  p[i]);
		i++;
	}
	free2dmalloc((void **)p, i);
	printf("\n");

	// do tests that may break the function
	printf("test 7\nft_split(0, 0)\n");
	p = ft_split(0, 0);
	i = 0;
	while (p && p[i])
	{
		printf("[%d]\t%s\n", i,  p[i]);
		i++;
	}
	free2dmalloc((void **)p, i);
	printf("\n");

	printf("test 8\nft_split(0, 'B')\n");
	p = ft_split(0, 'B');
	i = 0;
	while (p[i])
	{
		printf("[%d]\t%s\n", i,  p[i]);
		i++;
	}
	free2dmalloc((void **)p, i);
	printf("\n");

	printf("test 9\nft_split(0, 0)\n");
	p = ft_split(0, 0);
	i = 0;
	while (p[i])
	{
		printf("[%d]\t%s\n", i,  p[i]);
		i++;
	}
	free2dmalloc((void **)p, i);
}
*/