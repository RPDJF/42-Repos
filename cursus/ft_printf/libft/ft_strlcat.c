/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:44:51 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/16 19:57:20 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
* The strlcat() function appends the NUL-terminated string src to the end of
* dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating
* the result.
*
* The source and destination strings should not overlap, as the behavior is
* undefined.
*
* RETURN VALUES
* The strlcat() functions return the total length of the string they tried to
* create. For strlcat() that means the initial length of dst plus the length
* of src. While this may seem somewhat confusing, it was done to make
* truncation detection simple.
*/
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