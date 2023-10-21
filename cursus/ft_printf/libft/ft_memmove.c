/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:15:47 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/11 15:28:52 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	if (dest > src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
		return (dest);
	}
	else
		return (ft_memcpy(dest, src, n));
}

// check if same as memmove
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	// test the overlap case with multiple scenarios
	char	str[] = "123456789";
	char	str2[] = "123456789";
	char	str3[] = "123456789";
	char	str4[] = "123456789";
	char	str5[] = "123456789";
	char	str6[] = "123456789";
	char	str7[] = "123456789";
	char	str8[] = "123456789";

	printf("FT:\t%s\n", ft_memmove(str, str + 2, 5));
	printf("Real:\t%s\n", memmove(str2, str2 + 2, 5));

	printf("FT:\t%s\n", ft_memmove(str3 + 2, str3, 5));
	printf("Real:\t%s\n", memmove(str4 + 2, str4, 5));

	printf("FT:\t%s\n", ft_memmove(str5, str5 + 2, 5));
	printf("Real:\t%s\n", memmove(str6, str6 + 2, 5));

	printf("FT:\t%s\n", ft_memmove(str7, str7 + 2, 5));
	printf("Real:\t%s\n", memmove(str8, str8 + 2, 5));
	return (0);
}
*/