/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unify@outlook.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:44:51 by rude-jes          #+#    #+#             */
/*   Updated: 2023/11/09 16:45:42 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "betterft.h"
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
