/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 08:48:20 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/16 19:56:56 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

/*
* The strncat() function appends not more than n characters from s2, and then
* adds a terminating `\0'.
* The source and destination strings should not overlap, as the behavior is
* undefined.
* The strncat() function returns the pointer s1.
*/
char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	int	i;
	int	j;

	i = ft_strlen(dest);
	j = 0;
	while ((unsigned int)j < nb && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	dest[] = "hello";
	char	src[] = "HELLO";
	int		nb;

	nb = 3;
	printf("dest:\t%s\n", dest);
	printf("src:\t%s\n", src);
	printf("rslt:\t%s\n", ft_strncat(dest, src, nb));
}*/
