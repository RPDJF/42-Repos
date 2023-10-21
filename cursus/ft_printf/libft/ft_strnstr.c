/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:54:36 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/13 11:01:05 by rude-jes         ###   ########.fr       */
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
		while (needle[j] && haystack[i + j] == needle[j] && i + j < len)
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
	//char	str[] = "1234567589";

	printf("ft: \t%s\n", ft_strnstr(str, "1", 10));
	printf("real: \t%s\n", strnstr(str, "1", 10));
	printf("ft: \t%s\n", ft_strnstr(str, "4", 10));
	printf("real: \t%s\n", strnstr(str, "4", 10));
	printf("ft: \t%s\n", ft_strnstr(str, "5", 0));
	printf("real: \t%s\n", strnstr(str, "5", 0));
	printf("ft: \t%s\n", ft_strnstr("abcdefgh", "abc", 1));
	//printf("real: \t%s\n", strnstr("abcdefgh", "abc", 1));
	printf("ft: \t%s\n", ft_strnstr("aaxx", "xx", 2));
	//printf("real: \t%s\n", strnstr("aaxx", "xx", 2));
	printf("ft: \t%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
	return (0);
}*/