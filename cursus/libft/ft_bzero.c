/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:23:34 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/11 10:11:28 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
		str[i++] = 0;
}

// do main for testing
/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	int		i;

	i = 0;
	str = (unsigned char *)malloc(sizeof(char) * 10);
	while (i < 10)
	{
		str[i] = 'a';
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (str[i])
			printf("%d > %c\n", i, str[i]);
		i++;
	}
	ft_bzero(str, 5);
	i = 0;
	printf("======\n");
	while (i < 10)
	{
		if (str[i])
			printf("%d> %c\n", i, str[i]);
		i++;
	}
	return (0);
}
*/