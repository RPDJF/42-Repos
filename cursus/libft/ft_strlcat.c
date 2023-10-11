/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:44:51 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/11 13:05:50 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(dst);
	if (dstsize <= size)
		return (ft_strlen(src) + dstsize);
	i = 0;
	while (i + size < dstsize - 1 && src[i])
	{
		dst[i + size] = src[i];
		i++;
	}
	dst[i + size] = 0;
	return (ft_strlen(src) + size);
}

/*size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < dstsize)
		i++;
	if (i + 1 < dstsize)
	{
		while (i < dstsize && src[j] && i + j < dstsize - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = 0;
	}
	else
		return (dstsize + ft_strlen(src));
	return (i + j);
}
*/
// do main to test
/*
#include <stdio.h>
#include <string.h>
int main() {
    char dest[20] = "Hello, ";
    const char source[] = "world!";
    
    size_t result = ft_strlcat(dest, source, 2);

    printf("Result: %zu\n", result);
    printf("Destination (dest): \"%s\"\n", dest);
    printf("Output: %zu\n", ft_strlen(dest));

	// add the real strlcat to compare
	char dest2[20] = "Hello, ";
	char *source2 = "world!";
	size_t result2 = strlcat(dest2, source2, 2);
	printf("Real Result: %zu\n", result2);
	printf("Real Destination (dest): \"%s\"\n", dest2);
	printf("Real Output: %zu\n", strlen(dest2));

    return 0;
}*/

/*Result: 13
Expected Destination (dest): "Hello, world!"
Expected Output: 13*/