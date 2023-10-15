/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <rude-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 08:48:20 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/10 14:38:14 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

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
