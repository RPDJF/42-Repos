/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:27:54 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/15 13:36:08 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dstwriter;

	if (!dest && !src)
		return (0);
	dstwriter = dest;
	while (src++, dstwriter++, (size_t)dstwriter - 1 - (size_t)dest < n)
		*(dstwriter - 1) = *(unsigned char *)(src - 1);
	return (dest);
}

// do main for testing
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	// check if it works with NULL
	char	*src = NULL;
	char	*dest = NULL;
	char	*src2 = NULL;
	char    *dest2 = NULL;

	printf("%s\n", memcpy(dest2, src2, 5));
	printf("%s\n", ft_memcpy(dest, src, 5));
	return (0);
}
*/