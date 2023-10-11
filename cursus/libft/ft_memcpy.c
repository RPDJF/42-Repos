/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:27:54 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/11 15:15:47 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
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