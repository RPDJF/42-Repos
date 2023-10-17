/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:18:39 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/13 09:48:35 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}

// check if same as memchr
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "1234567589";

	printf("ft: \t%s\n", ft_memchr(str, '9', 10));
	printf("real: \t%s\n", memchr(str, '9', 10));
	printf("ft: \t%s\n", ft_memchr(str, '4', 10));
	printf("real: \t%s\n", memchr(str, '4', 10));
	printf("ft: \t%s\n", ft_memchr(str, '5', 0));
	printf("real: \t%s\n", memchr(str, '5', 0));
	return (0);
}
*/