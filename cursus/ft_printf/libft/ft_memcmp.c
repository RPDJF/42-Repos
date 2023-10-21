/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:45:01 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/10 14:20:33 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

// check if same as memcmp
/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char	str[] = "1834566589";

	printf("ft: \t%d\n", ft_memcmp(str, "1234567589", 10));
	printf("real: \t%d\n", memcmp(str, "1234567589", 10));
	printf("ft: \t%d\n", ft_memcmp(str, "1244567589", 5));
	printf("real: \t%d\n", memcmp(str, "1244567589", 5));
	printf("ft: \t%d\n", ft_memcmp(str, "1234567589", 0));
	printf("real: \t%d\n", memcmp(str, "1234567589", 0));
	return (0);
}
*/