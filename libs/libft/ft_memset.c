/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:22:37 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/11 15:05:02 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)b)[i++] = c;
	return (b);
}

// test the function with real memset
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "123456789";

	printf("%b\n", ft_memset(str, 'a', 5));
	printf("%b\n", memset(str, 'a', 5));
	return (0);
}*/