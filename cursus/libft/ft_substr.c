/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rude-jes <ruipaulo.unif@outlook.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:07:41 by rude-jes          #+#    #+#             */
/*   Updated: 2023/10/14 22:01:06 by rude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION	The  substr() function extracts a substring from the string 's'.
	The substring begins at position 'start' and is of maximum size 'len'.

	RETURN VALUES	If the allocation fails, the function returns NULL.
	Otherwise, it returns a pointer to the substring.
*/

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;

	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	p = (char *)ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (0);
	ft_memcpy(p, s + start, len);
	return (p);
}

/*#include <stdio.h>

int    main(void)
{
	char	*p;

	p = ft_substr("Bonjour", 3, 7);
	printf("%s\n", p);
	free(p);
}
*/