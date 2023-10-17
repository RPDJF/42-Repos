/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:23:34 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/14 22:04:26 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// do same desc as manual Man)
// bzero -- write zeroes to a byte string
// The bzero() function writes n zeroed bytes to the string s.

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
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