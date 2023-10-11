/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:54:36 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/10 14:53:05 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = ft_strlen(needle);
	if (size == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
			j++;
		if (j == size)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}

// check if same as strnstr
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "1234567589";

	printf("ft: \t%s\n", ft_strnstr(str, "1", 10));
	printf("real: \t%s\n", strnstr(str, "1", 10));
	printf("ft: \t%s\n", ft_strnstr(str, "4", 10));
	printf("real: \t%s\n", strnstr(str, "4", 10));
	printf("ft: \t%s\n", ft_strnstr(str, "5", 0));
	printf("real: \t%s\n", strnstr(str, "5", 0));
	return (0);
}
*/